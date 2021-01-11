//  Adapted from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.hpp  */
#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>
#include "Node.hpp"

using namespace std;

template<class ItemType>
class Stack
{
private:
	Node<ItemType>* headPtr; // Pointer to first node
	int currentSize;         // Current depth of the stack

public:
	/** Stack constructor */
	Stack();
	/** Returns the number of items on the stack.
	    @return The integer number of items on the stack. */
	int size() const;
	/** Determines whether this stack is empty.
	    @return True if the stack has no items, or false if not. */
	bool isEmpty() const;
	/** Pushes a new entry onto the top of the stack.
		@post  If successful, newItem is on the top of the stack.
        @param newItem  The item (of datatype ItemType) to be pushed on top of the stack.
		@return  True if insert was successful, or false if not. */
	bool push(const ItemType& newItem);
	/** Pops the top item off of the stack. The stack size is decreased by 1.
		@return  True if successful, or false otherwise. */
	bool pop();
	/** Returns the top item off of the stack without removing it. The stack size
	    stays the same.
		@return  Item of ItemType that was on the top of the stack. 
		Throws an exception of type logic_error if the stack is empty. */
	ItemType peek() const throw(logic_error);
	/** Deletes all entries on the stack.
	    @post  Stack contains no items, and the size of the stack is 0. */
	void clear();
	/** Stack destructor. Must delete any allocated memory. */
	virtual ~Stack();
}; // end Stack

#include "Stack.cpp"
#endif

