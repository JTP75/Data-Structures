cmake_minimum_required(VERSION 3.5)
PROJECT(AlgebraicExpressions CXX)

set(SOURCE postpre.cpp algebraic_expressions.cpp algebraic_expressions.hpp)

ADD_EXECUTABLE(postpre ${SOURCE})

ENABLE_TESTING()

# basic operators
ADD_TEST( test1 ${EXECUTABLE_OUTPUT_PATH}/postpre "ab+" )
set_tests_properties(test1 PROPERTIES PASS_REGULAR_EXPRESSION "(\\+)(a)(b)")

ADD_TEST( test2 ${EXECUTABLE_OUTPUT_PATH}/postpre "ab-" )
set_tests_properties(test2 PROPERTIES PASS_REGULAR_EXPRESSION "(-)(a)(b)")

ADD_TEST( test3 ${EXECUTABLE_OUTPUT_PATH}/postpre "ab*" )
set_tests_properties(test3 PROPERTIES PASS_REGULAR_EXPRESSION "(\\*)(a)(b)")

ADD_TEST( test4 ${EXECUTABLE_OUTPUT_PATH}/postpre "ab/" )
set_tests_properties(test4 PROPERTIES PASS_REGULAR_EXPRESSION "(\\/)(a)(b)")

# valid literals
ADD_TEST( test5 ${EXECUTABLE_OUTPUT_PATH}/postpre "aA+" )
set_tests_properties(test5 PROPERTIES PASS_REGULAR_EXPRESSION "(\\+)(a)(A)")

ADD_TEST( test6 ${EXECUTABLE_OUTPUT_PATH}/postpre "Xi+" )
set_tests_properties(test6 PROPERTIES PASS_REGULAR_EXPRESSION "(\\+)(X)(i)")

ADD_TEST( test7 ${EXECUTABLE_OUTPUT_PATH}/postpre "RR+" )
set_tests_properties(test7 PROPERTIES PASS_REGULAR_EXPRESSION "(\\+)(R)(R)")

ADD_TEST( test8 ${EXECUTABLE_OUTPUT_PATH}/postpre "qv+" )
set_tests_properties(test8 PROPERTIES PASS_REGULAR_EXPRESSION "(\\+)(q)(v)")

# more complex expressions
ADD_TEST( test9 ${EXECUTABLE_OUTPUT_PATH}/postpre "AB*CD/+" )
set_tests_properties(test9 PROPERTIES 
   PASS_REGULAR_EXPRESSION "(\\+)(\\*)AB(\\/)CD")

ADD_TEST( test10 ${EXECUTABLE_OUTPUT_PATH}/postpre "hr*Rf-+tg-ef/*-" )
set_tests_properties(test10 PROPERTIES 
  PASS_REGULAR_EXPRESSION "-(\\+)(\\*)hr-Rf(\\*)-tg(\\/)ef")

# expected failures
ADD_TEST( test11 ${EXECUTABLE_OUTPUT_PATH}/postpre "hr*Rf-+tg-ef/*" )
ADD_TEST( test12 ${EXECUTABLE_OUTPUT_PATH}/postpre "hr**Rf-+tg-ef/-" )
ADD_TEST( test13 ${EXECUTABLE_OUTPUT_PATH}/postpre "hr*f-+tgef/*-" )
ADD_TEST( test14 ${EXECUTABLE_OUTPUT_PATH}/postpre "hr*Rf-tg-ef/*-h" )
ADD_TEST( test15 ${EXECUTABLE_OUTPUT_PATH}/postpre "h*R+f-tg-ef/*" )

set_tests_properties( 
test11 
test12 
test13 
test14 
test15 
PROPERTIES WILL_FAIL true )

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw5_postfix_prefix.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})