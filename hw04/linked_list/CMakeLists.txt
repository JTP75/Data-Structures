cmake_minimum_required(VERSION 3.5)
project(LINKEDLIST CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build the test
add_executable(test_linked_list
  linked_list.tpp
  test_linked_list.cpp catch.hpp)

enable_testing()
add_test(test_linked_list test_linked_list)


