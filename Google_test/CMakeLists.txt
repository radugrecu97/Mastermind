# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(./googletest-release-1.10.0/googletest/include ./googletest-release-1.10.0/googletest)

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run tests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main peg_manager settings_manager util)