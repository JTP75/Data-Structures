cmake_minimum_required(VERSION 3.5)
project(LINKEDLIST CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE linked_list.hpp linked_list.tpp test_linked_list.cpp)

# build the test
add_executable(test_linked_list
   catch.hpp ${SOURCE})

enable_testing()
add_test(test_linked_list test_linked_list)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw4_list_linked.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}) 
