#ifndef cetlib_except_exception_h
#define cetlib_except_exception_h

// ======================================================================
//
//  exception: An exception type with category capability
//
// ----------------------------------------------------------------------
//
// Each exception is identified by a category string.  This string is a
// short word or phrase (no whitespace) describing the problem that was
// encountered.  These category identifiers can be concatenated when
// exceptions are caught and rethrown; the entire list can be accessed
// using the history() call.  Example:
//
//   try {
//     func();
//   }
//   catch (cet::exception & e)
//   {
//     throw cet::exception("DataCorrupt","encountered while unpacking",e);
//   }
//
// Information can be appended to the exception via operator <<.  Example:
//
//   if((rc=func()) < 0) {
//     throw cet::exception("DataCorrupt")
//       << "I died with rc = " << rc
//       << std::endl;
//   }
//
// ----------------------------------------------------------------------
//
// Derived types are expected to adjust the category, either
//   1) by passing a string literal to the base class constructor, or
//   2) by ensuring the developer gives a category name.
// Example:
//
//  class infinite_loop
//    : public cet::exception
//  {
//    infinite_loop(std::string const& mesg)
//      : exception("infinite_loop", mesg)
//    { }
//  };
//
// ----------------------------------------------------------------------
//
// The output from what() has a simple format that makes it easy to
// locate the reason for and context of the error and separate it from
// the user-supplied free-format text.  The output from what() contains
// all the category and context information in a nested hierarchical format.
//
// ======================================================================

#include <concepts>
#include <exception>
#include <iosfwd>
#include <list>
#include <sstream>
#include <string>
#include <type_traits>

namespace cet {
  class exception;

  std::ostream& operator<<(std::ostream& os, exception const& e);
}

// ======================================================================

namespace cet::detail {
  template <class T>
  concept cet_exception =
    std::is_base_of_v<cet::exception, std::remove_reference_t<T>>;

  template <typename T>
  concept Streamable = requires(std::ostream os, T value) { os << value; };
} // cet::detail

// ======================================================================

namespace cet {

  class exception : public std::exception {
  public:
    using Category = std::string;
    using CategoryList = std::list<Category>;

    // --- c'tors, d'tor:

    explicit exception(Category const& category);

    exception(Category const& category, std::string const& message);

    exception(Category const& category,
              std::string const& message,
              exception const& another);

    // The 'noexcept' keyword is applied to the copy c'tor to indicate
    // that if an exception escapes the copy constructor call, then an
    // immediate std::terminate() will be invoked.  Such a
    // circumstance would likely be a symptom of memory exhaustion, in
    // which case program recovery is incredibly unlikely.
    exception(exception const& other) noexcept;

    virtual ~exception() noexcept;

    // --- inspectors:

    char const* what() const noexcept override;
    virtual std::string explain_self() const;
    std::string category() const;
    CategoryList const& history() const;
    std::string root_cause() const;

    // --- mutators:

    void append(exception const& another);

    void append(std::string const& more_information);
    void append(char const more_information[]);

    void append(std::ostream& f(std::ostream&));
    void append(std::ios_base& f(std::ios_base&));

    template <detail::Streamable T>
    void
    append(T const& more_information)
    {
      ost_ << more_information;
    }

  private:
    std::ostringstream ost_{};
    CategoryList category_;
    mutable std::string what_{};

  }; // exception

  template <detail::cet_exception E>
  E&&
  operator<<(E&& e, std::string const& t)
  {
    e.append(t);
    return std::forward<E>(e);
  }

  template <detail::cet_exception E>
  E&&
  operator<<(E&& e, char const t[])
  {
    e.append(t);
    return std::forward<E>(e);
  }

  template <detail::cet_exception E>
  E&&
  operator<<(E&& e, std::ostream& f(std::ostream&))
  {
    e.append(f);
    return std::forward<E>(e);
  }

  template <detail::cet_exception E>
  E&&
  operator<<(E&& e, std::ios_base& f(std::ios_base&))
  {
    e.append(f);
    return std::forward<E>(e);
  }

  template <detail::cet_exception E, class T>
  E&&
  operator<<(E&& e, T const& t)
  {
    e.append(t);
    return std::forward<E>(e);
  }

} // namespace cet

// ======================================================================

// Local variables
// mode: c++
// End:
#endif /* cetlib_except_exception_h */

// Local Variables:
// mode: c++
// End:
