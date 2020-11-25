# ======================================================================
#
# Build/install script
#
# ======================================================================

include(CetMake)

cet_make_library(
  LIBRARY_NAME ${PROJECT_NAME}
  SOURCE
    demangle.cc
    exception.cc
    exception_collector.cc
)

install_headers()
install_source()

# ======================================================================
# Testing
add_subdirectory(test)
