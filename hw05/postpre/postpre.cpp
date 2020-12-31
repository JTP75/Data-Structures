/*
Converts algebraic expressions in postfix notation
to prefix notation. Valid operators are +,-,/, or *. Any
single alpha character is a valid operand.
 */

#include <cstdlib>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "algebraic_expressions.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Error: " << argv[0] << "requires one argument" << endl;
    return EXIT_FAILURE;
  }

  string postfix = string(argv[1]);
  string prefix;

  if (isPost(postfix)) {
    convert(postfix, prefix);
    cout << prefix.c_str() << endl;
  } else {
    cerr << "Error: input not in postfix format" << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
};
