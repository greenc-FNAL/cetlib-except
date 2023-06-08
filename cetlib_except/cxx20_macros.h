#ifndef cetlib_except_cxx20_macros_h
#define cetlib_except_cxx20_macros_h
#ifndef CET_CXX20_AVAILABLE
#define CET_CXX20_AVAILABLE (__cplusplus >= 202002L)
#endif
#ifndef CET_CONCEPTS_AVAILABLE
#define CET_CONCEPTS_AVAILABLE \
  (defined(__cpp_concepts) && __cpp_concepts >= 202002L)
#endif
#endif /* cetlib_except_cxx20_macros_h */
