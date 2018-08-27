#ifndef cetlib_except_demangle_h
#define cetlib_except_demangle_h

// ======================================================================
//
// demangle: Call the cross-vendor API to demangle symbols
//
// ======================================================================

#include <string>
#include <string_view>

namespace cet {
  std::string demangle_symbol(std::string_view symbol);
  std::string demangle_message(std::string mangled);
}

#endif /* cetlib_except_demangle_h */

// Local Variables:
// mode: c++
// End:
