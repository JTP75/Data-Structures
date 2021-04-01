cmake_minimum_required(VERSION 3.5)
project(BinarySearchTree)

set(SOURCE test_bst.cpp binary_search_tree.h binary_search_tree.tpp)

add_executable(test_bst test_bst.cpp binary_search_tree.h)
set_property(TARGET test_bst PROPERTY CXX_STANDARD 11)

enable_testing()

add_test(test_bst test_bst)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw9_binary_search_tree.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})  