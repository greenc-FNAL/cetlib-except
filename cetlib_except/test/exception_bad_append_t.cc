#include <catch2/catch_test_macros.hpp>

#include "cetlib_except/exception.h"

#include <concepts>
#include <ostream>

namespace {
  struct Streamable {
    int i;
  };
  std::ostream&
  operator<<(std::ostream& os, Streamable const& s)
  {
    return os << s.i;
  }
  struct UnStreamable {};
  template <typename T>
  concept can_append_to_exception =
    requires(cet::exception&& e, T const& t) { e.append(t); };
}

TEST_CASE("Ensure streamable exception append")
{
  REQUIRE(can_append_to_exception<Streamable>);
  REQUIRE_FALSE(can_append_to_exception<UnStreamable>);
}
