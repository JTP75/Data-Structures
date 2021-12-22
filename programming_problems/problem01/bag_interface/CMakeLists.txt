cmake_minimum_required(VERSION 3.5)
project(bag_interface CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE bag_tests.cpp abstract_bag.hpp bag_simple.hpp bag_simple.tpp)

# create unittests
add_executable(bag-tests catch.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(test-bag bag-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem01_bag_interface.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     