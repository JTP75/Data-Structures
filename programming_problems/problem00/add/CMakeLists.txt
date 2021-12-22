cmake_minimum_required(VERSION 3.5)
project(add CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE add_tests.cpp abstract_operator.hpp add.hpp add.tpp)

# create unittests
add_executable(add-tests catch.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(test-add add-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem00_add.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     