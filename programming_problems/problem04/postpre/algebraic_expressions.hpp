/*
Definition of functions for testing validity of postfix expressions
and conversion to prefix notation.
 */

#ifndef _ALGEBRAICEXPRESSIONS_HPP_
#define _ALGEBRAICEXPRESSIONS_HPP_

#include <string>

// Determine if a character is a valid operator
// if ch is one of +,-,/,* return true, else
// return false
// Preconditions: none
bool isoperator(char ch);

// Return index to the last valid postfix expression
// in the string s, beginning at index last.
// Preconditions: last >= 0
int endPost(std::string s, int last);

// Determine if the string s is a valid postfix expression
// Preconditions: none
bool isPost(std::string s);

// Convert the input expression postfix to prefix
// Preconditions: postfix is a valid postfix expression
void convert(std::string &postfix, std::string &prefix);

#endif // _ALGEBRAICEXPRESSIONS_HPP_
