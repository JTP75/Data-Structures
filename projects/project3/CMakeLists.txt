cmake_minimum_required(VERSION 3.5)
project(P2 CXX)

#require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# some definitions
set(CODE_TO_SUBMIT Stack.cpp XMLParser.hpp XMLParser.cpp XMLParser_test.cpp)
set(SOURCE_STACK_MAIN mainStack.cpp)
set(SOURCE_XMLPARSER XMLParser.cpp)
set(SOURCE_XMLPARSER_TEST XMLParser.cpp XMLParser_test.cpp)
set(SOURCE_XMLPARSER_MAIN XMLParser.cpp mainXMLParser.cpp)

# create unittests
add_executable(XMLParser-tests catch.hpp ${SOURCE_XMLPARSER_TEST})

enable_testing()

# unit tests
add_test(unittest XMLParser-tests)

# add a mainStack executable
add_executable (mainStack ${SOURCE_STACK_MAIN})

# add a mainXMLParser executable
add_executable (mainXMLParser ${SOURCE_XMLPARSER_MAIN})

# a rule to create the submission zip file
add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/p3_xml_parser.zip" --format=zip
    ${CODE_TO_SUBMIT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
	     
