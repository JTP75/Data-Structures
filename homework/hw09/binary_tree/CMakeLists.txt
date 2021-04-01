cmake_minimum_required(VERSION 3.5)
project(BINARY_TREE CXX)

set(SOURCE test.cpp BinaryTree.h BinaryTree.tpp)

ADD_EXECUTABLE( testBinaryTree 
test.cpp
TreeException.h
BinaryTree.h
BinaryTree.tpp )

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw9_binary_tree.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})  