#include "cetlib_except/coded_exception.h"
#include <cstdlib>
#include <map>
#include <string>

using cet::coded_exception;

void
ensure(int which, bool claim)
{
  if (not claim)
    std::exit(which);
}

enum E { E1 = 1, E2, E3, E4 };
using Emap = std::map<E, std::string>;

std::string
mapper(E code)
{
  switch (code) {
  case E1:
    return "E1";
  case E2:
    return "E2";
  case E3:
    return "E3";
  default:
    return "Unknown";
  }
}

int
main()
{

  {
    coded_exception<E, mapper> e(E1);
    ensure(1, e.categoryCode() == E1);
    ensure(2, e.returnCode() == static_cast<int>(E1));
    ensure(3, e.category() == "E1");
  }

  {
    coded_exception<E, mapper> e(E4);
    ensure(11, e.categoryCode() == E4);
    ensure(12, e.returnCode() == static_cast<int>(E4));
    ensure(13, e.category() == "Unknown");
  }

  {
    auto codeToString = coded_exception<E, mapper>::codeToString;
    ensure(21, codeToString(E1) == mapper(E1));
    ensure(22, codeToString(E2) == mapper(E2));
    ensure(23, codeToString(E3) == mapper(E3));
    ensure(24, codeToString(E4) == mapper(E4));
  }

  return 0;

} // main()
