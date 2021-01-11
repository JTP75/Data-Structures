cmake_minimum_required(VERSION 3.5)
project(PQH CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE dynamic_array_list.tpp test_priority_queue.cpp)

# create unittests
add_executable(test_priority_queue ${SOURCE})

