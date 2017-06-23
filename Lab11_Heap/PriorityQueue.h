/*!@file
* @author Joshua Forsyth
* @date 03/30/17
* @brief Class declaration for the heap implementation of the PriorityQueue ADT. */

#pragma once
#include "Heap.cpp"

//! Default maximum queue size.
const int defMaxQueueSize = 10;

//! Declaration of the PriorityQueue ADT
/*! @tparam DataType The type of object that the PriorityQueue will contain.
* @tparam KeyType The type of object used to represent the priority of an object.
* @tparam The type of object to use to perform the priority comparison operation. */
template < typename DataType, typename KeyType=int, typename Comparator=Less<KeyType> >
class PriorityQueue : public Heap<DataType, KeyType, Comparator>
{
public:

	//! Constructor. Creates an empty priority queue.
	/*! Allocates enough memory for a priority queue containing maxNumber data items. 
	 * @param[in] maxNumber The maximum number of items that the PriorityQueue will contain. */
	PriorityQueue(int maxNumber = defMaxQueueSize);

	//! Enqueues the given dataItem.
	/*! @param[in] newDataItem A reference to the data item to be enqueued */
	void enqueue(const DataType &newDataItem);

	//! Dequeues a data item.
	/*! @return The data item that was dequeued. */
	DataType dequeue();
};
