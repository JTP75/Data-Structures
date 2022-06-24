#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"


// swap
template<typename T> bool swap(LinkedList<T> &list, std::size_t a, std::size_t b)
{
	if(a >= list.getLength() || b >= list.getLength())
		return false;
	
	T tmp = list.getEntry(a);
	list.setEntry(a, list.getEntry(b));
	list.setEntry(b, tmp);
	return true;
}

// quicksort
template<typename T> LinkedList<T> qsort(LinkedList<T> list, std::size_t start, std::size_t end)
{
	// base case
	if(start >= end || end >= list.getLength())								// check if ends meet (also make sure inputs are valid)
		return list;														// return list
	
	// partition
	T pivot_val = list.getEntry(start);										// init pivot at start so as to index from beginning
	std::size_t pivot_idx = start;											// pivot index = start ^^
	for(std::size_t i = start + 1; (i <= end && pivot_idx < end); i++){		// loop through list start to end (break if pivot_idx = end)
		swap(list, pivot_idx + 1, i);										// swap value at i with value in front of pivot
		if(pivot_val > list.getEntry(pivot_idx + 1)){						// compare pivot to value in front
			swap(list, pivot_idx, pivot_idx + 1);							// if pivot is greater, swap it with value in front
			pivot_idx++;													// increment idx
		}
	}

	// recursive calls
	list = qsort(list, start, pivot_idx);									// recursive call for lower half
	list = qsort(list, pivot_idx + 1, end);									// recursive call for upper half

	// return list
	return list;
}

// sort
template<typename T> LinkedList<T> sort(LinkedList<T> list){
	return qsort(list,0,list.getLength()-1);
}

#endif
