cmake_minimum_required(VERSION 3.2)
project(sorted_linked CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_sorted_linked_list.cpp linked_list.hpp linked_list.tpp sorted_linked_list.hpp sorted_linked_list.tpp) 

# build the test
add_executable(test_sorted_linked_list catch.hpp ${SOURCE})

enable_testing()
add_test(test_sorted_linked_list test_sorted_linked_list)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem07_sorted_linked_list.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})