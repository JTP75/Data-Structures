cmake_minimum_required(VERSION 3.5)
project(P1 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE FindPalindrome.cpp FindPalindrome.hpp FindPalindrome_test.cpp)
set(SOURCE_MAIN FindPalindrome.cpp FindPalindrome.hpp)

# create unittests
add_executable(FindPalindrome-tests catch.hpp ${SOURCE})
add_executable(FindPalindrome-main FindPalindrome_main.cpp ${SOURCE_MAIN})

enable_testing()

# unit tests
add_test(unittest FindPalindrome-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/p2_palindrome.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     
