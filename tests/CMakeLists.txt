# https://gitlab.kitware.com/cmake/cmake/-/issues/8774
add_custom_target(
  check
  COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
  COMMENT "Build and run tests"
  USES_TERMINAL)

find_package(doctest CONFIG REQUIRED)

# Add a test.
function(do_test testfile)
  string(REPLACE ".cpp" "" testname ${testfile})
  set(testexe "${testname}.exe")
  add_executable(${testexe} ${ARGV})
  target_link_libraries(${testexe} PRIVATE mylib)
  target_link_libraries(${testexe} PRIVATE doctest::doctest)
  add_test(${testname} ${testexe})
  add_dependencies(check ${testexe})
  # Tests are in general dirty. Excluded from static code analysis.
  set_target_properties(${testexe} PROPERTIES CXX_CLANG_TIDY "")
endfunction()

# Tests.
do_test(test-mylib.cpp)
