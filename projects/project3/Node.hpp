//  Adapted from Frank M. Carrano and Timothy M. Henry.

/** @file Node.hpp  */
#ifndef NODE_HPP
#define NODE_HPP

template<class ItemType>
class Node
{
private:
	ItemType        item; // A data item
	Node<ItemType>* next; // Pointer to next node

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const ;
	Node<ItemType>* getNext() const ;
}; // end Node

#include "Node.tpp"
#endif
