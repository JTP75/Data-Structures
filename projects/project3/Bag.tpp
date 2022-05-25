// Methods from Frank M. Carrano and Tim Henry.
// This file is included in "Bag.hpp"

/** @file Bag.cpp */

#include <algorithm>
#include <cstddef>

template<class ItemType>
Bag<ItemType>::Bag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
int Bag<ItemType>::size() const
{
	return itemCount;
}  // end size

template<class ItemType>
bool Bag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool Bag<ItemType>::add(const ItemType& newEntry)
{
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)
	Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

	headPtr = nextNodePtr;          // New node is now first node
	itemCount++;

	return true;                    // The method is always successful
}  // end add

template<class ItemType>
void Bag<ItemType>::clear()
{
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();
		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = headPtr;
	}  // end while
	// headPtr is nullptr; nodeToDeletePtr is nullptr

	itemCount = 0;
}  // end clear

template<class ItemType>
Node<ItemType>* Bag<ItemType>::getPointerTo(const ItemType& target) const
{
	bool found = false;
	Node<ItemType>* curPtr = headPtr;

	while (!found && (curPtr != nullptr))
	{
		if (target == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while

	return curPtr;
} // end getPointerTo

template<class ItemType>
bool Bag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

template<class ItemType>
int Bag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		} // end if

		counter++;
		curPtr = curPtr->getNext();
	} // end while

	return frequency;
}  // end getFrequencyOf

template<class ItemType>
std::vector<ItemType> Bag<ItemType>::toVector() const
{
	std::vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}  // end while

	return bagContents;
}  // end toVector

template<class ItemType>
Bag<ItemType>::~Bag()
{
	   clear();
}  // end destructor

