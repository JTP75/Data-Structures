cmake_minimum_required(VERSION 3.5)
project(Ex7 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE limited_size_bag_tests.cpp limited_size_bag.hpp limited_size_bag.tpp)

# create unittests
add_executable(bag-tests catch.hpp abstract_bag.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(unittest bag-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw3_limited_size_bag.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     