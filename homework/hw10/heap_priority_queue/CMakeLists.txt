cmake_minimum_required(VERSION 3.5)
project(PQH CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE heap_priority_queue.h test_priority_queue.cpp) 

# create unittests
add_executable(test_priority_queue ${SOURCE})

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw10_priority_queue_heap.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})  

