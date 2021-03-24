cmake_minimum_required(VERSION 3.5)
project(P0 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE dynamic_array_list.tpp sorted_list.tpp)

# create unittests
add_executable(sortedListTests test_sorted_list.cpp catch.hpp ${SOURCE})
add_executable(priorityQueueTests test_priority_queue.cpp catch.hpp ${SOURCE})
#enable_testing()

# unit tests
#add_test(unittest <testercode>)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw8_priority_queue.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})   