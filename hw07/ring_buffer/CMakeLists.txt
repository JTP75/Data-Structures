cmake_minimum_required(VERSION 3.5)
project(P0 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE ring_buffer.tpp test_ring_buffer.cpp)

# create unittests
add_executable(test_ring_buffer ${SOURCE})

