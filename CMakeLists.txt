cmake_minimum_required(VERSION 3.16)
project(MASTERMIND)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE_ON)

add_subdirectory(Google_test)
add_subdirectory(src)