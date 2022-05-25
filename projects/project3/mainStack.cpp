//  Adapted from Frank M. Carrano and Timothy M. Henry.

#include <iostream>
#include "Stack.hpp"

using namespace std;

int main()
{
	Stack<char> myCharStack;

	// Put the alphabet on the stack backwards...
	cout << endl << "*** Adding stuff to the stack ***" << endl;
	for (char c='z'; c>='a'; c--)
	{
		myCharStack.push(c);
		cout << c << " ";
	}

	// print out what is on the stack...
	cout << endl << endl << "*** Printing out stack contents ***" << endl;
	char value;
	while (!myCharStack.isEmpty()) {
		value = myCharStack.peek();
		myCharStack.pop();
		cout << value << " ";
	}

	// check to see if exceptions work when we do something bad...
	cout << endl << endl << "*** Peeking at an empty stack ***" << endl;
	try {
		value = myCharStack.peek();
		cout << "Result from peek of empty stack... " << value <<  endl;
	} catch (logic_error e) {
		cout << "Caught a logic error exception..." << endl;
	} catch (exception e) {
		cout << "Caught an exception that is not a logic error..." << endl;
	}
	cout << endl;

	return 0;
}  // end main

