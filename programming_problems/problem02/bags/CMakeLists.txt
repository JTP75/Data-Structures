cmake_minimum_required(VERSION 3.5)
project(bags CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE abstract_bag.hpp dynamic_bag_tests.cpp dynamic_bag.hpp dynamic_bag.tpp limited_size_bag_tests.cpp limited_size_bag.hpp limited_size_bag.tpp)

# create unittests
add_executable(dynamic-bag-tests catch.hpp abstract_bag.hpp dynamic_bag_tests.cpp dynamic_bag.hpp dynamic_bag.tpp)
add_executable(limited-size-bag-tests catch.hpp abstract_bag.hpp limited_size_bag_tests.cpp limited_size_bag.hpp limited_size_bag.tpp)

enable_testing()

# unit tests
add_test(test-dynamic dynamic-bag-tests)
add_test(test-limited limited-size-bag-tests) 

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem02_bags.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
      