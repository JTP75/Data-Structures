cmake_minimum_required(VERSION 3.5)
project(bst)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_bst.cpp binary_search_tree.hpp binary_search_tree.tpp)

add_executable(test-bst test_bst.cpp binary_search_tree.hpp binary_search_tree.tpp)

enable_testing()

add_test(test-bst test-bst)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem08_binary_search_tree.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})  