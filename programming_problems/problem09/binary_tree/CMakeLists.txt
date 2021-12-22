cmake_minimum_required(VERSION 3.5)
project(BINARY_TREE CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_binary_tree.cpp BinaryTree.hpp BinaryTree.tpp)

ADD_EXECUTABLE(test_binary_tree TreeException.hpp ${SOURCE})

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw9_binary_tree.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})  