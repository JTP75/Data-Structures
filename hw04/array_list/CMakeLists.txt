cmake_minimum_required(VERSION 3.5)
project(L17 CXX)

add_executable(test_array_list array_list.hpp array_list.tpp catch.hpp test_array_list.cpp)

enable_testing()

add_test(test_array_list test_array_list)
