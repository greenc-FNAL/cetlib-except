# ======================================================================
#
# Build/install script
#
# ======================================================================

include(CetMake)

# If someone is using cetlib_except::Catch2Matchers, they will be
# calling (cet)?find_package(Catch2) themselves.
cet_find_package(Catch2 PRIVATE REQUIRED)

cet_make_library(HEADERS_TARGET
  SOURCE
    demangle.cc
    exception.cc
    exception_collector.cc
)

cet_make_library(LIBRARY_NAME Catch2Matchers INTERFACE
  SOURCE exception_message_matcher.h exception_category_matcher.h
  LIBRARIES INTERFACE cetlib_except::cetlib_except
      #      Catch2::Catch2
      #
      # See note above. We can put this back if this target is
      # registered as an optional component; otherwise either (a)
      # find_package(Catch2 PRIVATE REQUIRED) must precede any direct or
      # indirect invocation of find_package(cetlib_except) in any
      # package needing this target; or (b) every dependent of
      # cetlib_except inherits a dependency on Catch2.
)

install_headers()
install_source()

# ======================================================================
# Testing
add_subdirectory(test)
