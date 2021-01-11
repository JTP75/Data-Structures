cmake_minimum_required(VERSION 3.5)
project(Ex4 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE bag_tests.cpp abstract_bag.hpp bag_simple.hpp bag_simple.tpp)

# create unittests
add_executable(bag-tests catch.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(unittest bag-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw2_bag_interface.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     