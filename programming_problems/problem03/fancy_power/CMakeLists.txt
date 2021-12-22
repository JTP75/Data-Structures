cmake_minimum_required(VERSION 3.5)
project(powers CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE fancy_power_tests.cpp fancy_power.hpp)

# create unittests
add_executable(fancy-power-tests catch.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(unittest fancy-power-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem03_fancy_power.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     
