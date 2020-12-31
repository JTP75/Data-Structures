cmake_minimum_required(VERSION 2.8)
project(BinarySearchTree)

add_executable(test_bst test_bst.cpp binary_search_tree.h)
set_property(TARGET test_bst PROPERTY CXX_STANDARD 11)

enable_testing()

add_test(test_bst test_bst)
