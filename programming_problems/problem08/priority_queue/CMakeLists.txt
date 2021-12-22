cmake_minimum_required(VERSION 3.5)
project(priorityqueue CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_priority_queue.cpp abstract_list.hpp abstract_priority_queue.hpp abstract_sorted_list.hpp dynamic_array_list.hpp dynamic_array_list.tpp sorted_list.hpp sorted_list.tpp priority_queue.hpp)

# create unittests
add_executable(test-priority-queue test_priority_queue.cpp catch.hpp ${SOURCE})
enable_testing()

# unit tests
add_test(test-priority-queue test-priority-queue)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem08_priority_queue.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})   