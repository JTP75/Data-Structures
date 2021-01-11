cmake_minimum_required(VERSION 3.5)
project(Ex6 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE fancyPower_tests.cpp fancyPower.hpp)

# create unittests
add_executable(fancyPower-tests catch.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(unittest fancyPower-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw3_egyptian_power.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     
