cmake_minimum_required(VERSION 3.5)
project(Ex08 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE dynamic_bag_tests.cpp dynamic_bag.hpp dynamic_bag.tpp)

# create unittests
add_executable(dynamic-bag-tests catch.hpp abstract_bag.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(unittest dynamic-bag-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw3_dynamic_bag.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
      