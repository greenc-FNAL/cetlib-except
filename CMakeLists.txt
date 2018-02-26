# ======================================================================
#  cetlib main build file
#
#  cd .../path/to/build/directory
#  source .../path/to/cetlib/ups/setup_for_development
#  cmake [-DCMAKE_INSTALL_PREFIX=/install/path]
#        -DCMAKE_BUILD_TYPE=$CETPKG_TYPE
#        $CETPKG_SOURCE
#  make
#  make test
#  make install
#  make package (builds distribution tarfile)
# ======================================================================


# ----------------------------------------------------------------------
# Describe build tool requirements:

cmake_minimum_required(VERSION 3.0)  

# ----------------------------------------------------------------------
# Describe product:

project(cetlib_except VERSION 1.01.02)

# what is our path?
message(STATUS "prefix path: ${CMAKE_PREFIX_PATH}")
# cetmodules contains our cmake modules
find_package(cetmodules REQUIRED)

include(CetCMakeEnv)
cet_cmake_env()

cet_set_compiler_flags(DIAGS VIGILANT
  WERROR
  NO_UNDEFINED
  EXTRA_FLAGS -pedantic
  EXTRA_CXX_FLAGS -Wnon-virtual-dtor -Wdelete-non-virtual-dtor
  )
cet_report_compiler_flags()

# ----------------------------------------------------------------------
# Describe build prerequisites:


find_ups_product (cetmodules)

# ----------------------------------------------------------------------
# Describe source tree layout:

add_subdirectory( ${PROJECT_NAME} )  # source code
add_subdirectory( ups )              # ups files

# ----------------------------------------------------------------------
# Packaging utility

##include(UseCPack)

#
# ======================================================================
