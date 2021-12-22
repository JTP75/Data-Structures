cmake_minimum_required(VERSION 3.5)
project(queue CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_queue.cpp abstract_list.hpp abstract_queue.hpp dynamic_array_list.hpp dynamic_array_list.tpp queue.hpp)

# create unittests
add_executable(test-queue ${SOURCE})

enable_testing()
add_test(test-queue test-queue)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem07_queue.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
      
