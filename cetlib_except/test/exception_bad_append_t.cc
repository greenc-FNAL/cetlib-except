#include "cetlib_except/exception.h"
using cet::exception;

namespace {
  struct UnStreamable {
  };
}

int
main()
{
  exception e("Hello");
  e << UnStreamable{};
}
