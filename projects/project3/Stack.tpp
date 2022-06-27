//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include <type_traits>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class T>
Stack<T>::Stack() : currentSize(0), headptr(nullptr) {}	// end default constructor

// TODO: Implement the destructor here
template<class T>
Stack<T>::~Stack(){
	Node<T> *ptr = headptr, *tmp;
	while(ptr != nullptr){
		tmp = ptr;
		ptr = ptr->getNext();
		delete tmp;
	}
}  // end destructor

// TODO: Implement the isEmpty method here
template<class T>
bool Stack<T>::isEmpty() const{
	return currentSize == 0;
}  // end isEmpty

// TODO: Implement the size method here
template<class T>
int Stack<T>::size() const{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class T>
bool Stack<T>::push(const T& newItem){
	Node<T> *newptr = new Node<T>(newItem, headptr);
	headptr = newptr;
	currentSize++;
	return true;
}  // end push

// TODO: Implement the peek method here
template<class T>
T Stack<T>::peek() const{
	if(currentSize <= 0 || headptr == nullptr)
		throw std::logic_error("Stack is empty");
	return headptr->getItem();
}  // end peek

// TODO: Implement the pop method here
template<class T>
bool Stack<T>::pop() {
	if(currentSize <= 0 || headptr == nullptr)
		return false;
	Node<T> *ptr = headptr;
	headptr = headptr->getNext();
	delete ptr;
	currentSize--;
	return true;
}  // end pop

// TODO: Implement the clear method here
template<class T>
void Stack<T>::clear(){
	Node<T> *ptr = headptr, *tmp;
	while(ptr != nullptr){
		tmp = ptr;
		ptr = ptr->getNext();
		delete tmp;
	}
	currentSize = 0;
	headptr = nullptr;
}  // end clear

