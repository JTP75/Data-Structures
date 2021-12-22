cmake_minimum_required(VERSION 3.5)
project(P2 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE FindPalindrome.cpp FindPalindrome.hpp FindPalindrome_test.cpp)

# create unittests
add_executable(FindPalindrome-tests catch.hpp ${SOURCE})

enable_testing()

# unit tests
add_test(test-palindrome FindPalindrome-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/p2_palindrome.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     
