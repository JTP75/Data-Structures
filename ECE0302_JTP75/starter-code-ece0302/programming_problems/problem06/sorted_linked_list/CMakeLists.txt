cmake_minimum_required(VERSION 3.2)
project(sorted_linked CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_sorted_linked_list.cpp abstract_list.hpp abstract_sorted_list.hpp linked_list.hpp linked_list.tpp Node.hpp Node.tpp sorted_linked_list.hpp sorted_linked_list.tpp) 

# build the test
add_executable(test-sorted-linked-list catch.hpp ${SOURCE})

enable_testing()
add_test(test-sorted-linked-list test-sorted-linked-list)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem06_sorted_linked_list.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})