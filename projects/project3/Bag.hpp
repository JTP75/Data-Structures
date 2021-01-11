//  Based on code from Frank M. Carrano and Tim Henry.

/** ADT bag: Dynamic, array-based implementation.
 @file Bag.hpp */

#ifndef BAG_HPP
#define BAG_HPP

#include <vector>
#include "Node.hpp"

template<class ItemType>
class Bag
{
private:
	Node<ItemType>* headPtr; // Pointer to first node
	int itemCount;           // Current number of items in bag

	/** Private helper function.
	Returns either a pointer to the node containing a given item,
	or the null pointer if the item is not in the linked DS */
	Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
	/** Constructor */
	Bag(); 
	/** Destructor */
	~Bag();
	/** Returns the number of items in the bag.
	    @return The integer number of items in bag. */
	int size() const;
	/** Determines whether this bag is empty.
	    @return True if the bag has no items, or false if not. */
	bool isEmpty() const;
	/** Adds a new item to the bag.
		@post  If successful, newEntry is added to the bag,
	    and the number of items in the bag has increased by 1.
	    @param newItem  The item (of datatype ItemType) to be added.
		@return  True if insert was successful, or false if not. */
	bool add(const ItemType& newEntry);
	/** Deletes all entries from this bag.
	    @post  The bag contains no items, and the number of items is 0. */
	void clear();
	/** Tests whether this bag contains a given item.
		@param anItem  The item to locate.
		@return  True if bag contains anEntry, or false otherwise. */
	bool contains(const ItemType& anEntry) const;
	/** Returns the number of times a given item appears in this bag.
		@param anItem  The item to locate.
		@return  The integer number of times the item is in this bag. */
	int getFrequencyOf(const ItemType& anEntry) const;
	/** Empties and then fills a given vector with all items that
	are in this bag.
		@return  A vector containing all the items in the bag. */
	std::vector<ItemType> toVector() const;
};  // end Bag

// Include the source for the template class
#include "Bag.cpp"

#endif
