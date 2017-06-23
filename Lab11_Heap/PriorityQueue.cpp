/*!@file
 * @author Joshua Forsyth
 * @date 03/30/17
 * @brief Implementation of the PriorityQueue ADT */
#include "PriorityQueue.h"

template <typename DataType, typename KeyType, typename Comparator>
PriorityQueue<DataType, KeyType, Comparator>::PriorityQueue(int maxNumber) 
	: Heap<DataType, KeyType, Comparator>(maxNumber)
{
}

template <typename DataType, typename KeyType, typename Comparator>
void PriorityQueue<DataType, KeyType, Comparator>::enqueue(const DataType& newDataItem)
{
	Heap<DataType, KeyType, Comparator>::insert(newDataItem);
}

template <typename DataType, typename KeyType, typename Comparator>
DataType PriorityQueue<DataType, KeyType, Comparator>::dequeue()
{
	return Heap<DataType, KeyType, Comparator>::remove();
}
