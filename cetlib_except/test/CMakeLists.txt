# ======================================================================
#
# Testing
#
# ======================================================================

include(CetTest)
cet_enable_asserts()

# Identify libraries to be linked:
link_libraries(cetlib_except)

cet_test(coded_exception_test)
cet_test(exception_category_matcher_t USE_CATCH_MAIN)
cet_test(exception_collector_test)
cet_test(exception_message_matcher_t USE_CATCH_MAIN)
cet_test(exception_test)
cet_test(demangle_t)
