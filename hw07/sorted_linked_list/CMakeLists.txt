cmake_minimum_required(VERSION 3.2)
project(SortedList_LinkedList CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build the test
add_executable(test_sorted_linked_list test_sorted_linked_list.cpp catch.hpp)

enable_testing()
add_test(test_sorted_linked_list test_sorted_linked_list)
