cmake_minimum_required(VERSION 3.5)
project(P0 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE ring_buffer.tpp test_ring_buffer.cpp)

# create unittests
add_executable(test_ring_buffer ${SOURCE})

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw7_ring_buffer.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
      
