cmake_minimum_required(VERSION 3.5)
project(graph CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_list_graph.cpp test_matrix_graph.cpp abstract_graph.hpp adjacency_list_graph.hpp adjacency_list_graph.tpp adjacency_matrix_graph.hpp adjacency_matrix_graph.tpp) 

# create unittests
add_executable(test-matrix-graph catch.hpp test_matrix_graph.cpp abstract_graph.hpp adjacency_matrix_graph.hpp adjacency_matrix_graph.tpp)
add_executable(test-list-graph catch.hpp test_list_graph.cpp abstract_graph.hpp adjacency_list_graph.hpp adjacency_list_graph.tpp)

enable_testing()

add_test(test-matrix-graph test-matrix-graph)
add_test(test-list-graph test-list-graph)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem09_graph.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})  

