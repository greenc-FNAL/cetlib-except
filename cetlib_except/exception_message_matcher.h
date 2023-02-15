#ifndef cetlib_except_exception_message_matcher_h
#define cetlib_except_exception_message_matcher_h
////////////////////////////////////////////////////////////////////////
// exception_message_matcher
//
// Utility for matching cet::exception messages when one is using the
// Catch unit testing package.
//
// Initialize with any valid dstring matcher function (Contains(),
// EndsWith(), Regex(), etc.).
//
// Composable with other bases of Catch::MatcherBase<cet::exception>
// such as cet::exception_category_matcher.
////////////////////////////////////////////////////////////////////////
#include "cetlib_except/exception.h"
#include <catch2/matchers/catch_matchers_string.hpp>

#include <memory>
#include <string>

namespace cet {
  class exception_message_matcher;
}

class cet::exception_message_matcher
  : public Catch::Matchers::MatcherBase<cet::exception> {
public:
  exception_message_matcher(Catch::Matchers::StringEqualsMatcher const& matcher)
    : matcher_{std::make_shared<Catch::Matchers::StringEqualsMatcher>(matcher)}
    , description_{matcher.describe()}
  {}

  exception_message_matcher(
    Catch::Matchers::StringContainsMatcher const& matcher)
    : matcher_{std::make_shared<Catch::Matchers::StringContainsMatcher>(
        matcher)}
    , description_{matcher.describe()}
  {}

  exception_message_matcher(Catch::Matchers::StartsWithMatcher const& matcher)
    : matcher_{std::make_shared<Catch::Matchers::StartsWithMatcher>(matcher)}
    , description_{matcher.describe()}
  {}

  exception_message_matcher(Catch::Matchers::EndsWithMatcher const& matcher)
    : matcher_{std::make_shared<Catch::Matchers::EndsWithMatcher>(matcher)}
    , description_{matcher.describe()}
  {}

  exception_message_matcher(Catch::Matchers::RegexMatcher const& matcher)
    : matcher_{std::make_shared<Catch::Matchers::RegexMatcher>(matcher)}
    , description_{matcher.describe()}
  {}

  bool
  match(cet::exception const& e) const override
  {
    return matcher_->match(e.what());
  }

  std::string
  describe() const override
  {
    return description_;
  }

private:
  std::shared_ptr<Catch::StringMatcher> matcher_;
  std::string description_;
};

#endif /* cetlib_except_exception_message_matcher_h */

// Local Variables:
// mode: c++
// End:
