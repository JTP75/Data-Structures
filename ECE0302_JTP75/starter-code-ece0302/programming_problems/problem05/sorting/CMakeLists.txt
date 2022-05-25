cmake_minimum_required(VERSION 3.5)
project(sorting CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE sort_tests.cpp sort.hpp abstract_list.hpp linked_list.hpp linked_list.tpp Node.hpp Node.tpp)

# create unittests
add_executable(sort-tests catch.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(test-sorting sort-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem05_sorting.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     
