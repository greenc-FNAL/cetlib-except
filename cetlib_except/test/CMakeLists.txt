# ======================================================================
# Testing
# ======================================================================

include(CetTest)
cet_enable_asserts()

set(only_cetlib_except_tests
    coded_exception_test
    exception_collector_test
    exception_test
    demangle_t)
foreach(test IN LISTS only_cetlib_except_tests)
  cet_test(${test}
           LIBRARIES PRIVATE cetlib_except::cetlib_except)
endforeach()

# Catch2-dependent tests
set(catch2_tests
    exception_category_matcher_t
    exception_message_matcher_t)
foreach(test IN LISTS catch2_tests)
  cet_test(${test}
           USE_CATCH2_MAIN
           LIBRARIES PRIVATE cetlib_except::cetlib_except Catch2::Catch2)
endforeach()
