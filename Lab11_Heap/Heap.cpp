/*!@file
* @author Joshua Forsyth
* @date 03/30/17
* @brief Implementation of the Heap ADT
*/

#include "Heap.h"
#include <algorithm>

//! Gets the index of the parent
#define PARENT(child) (child - 1) / 2

//! Gets the index of the left child
#define LEFT(parent) 2 * parent + 1

//! Gets the index of the right child
#define RIGHT(parent) 2 * parent + 2

template <typename DataType, typename KeyType, typename Comparator>
Heap<DataType, KeyType, Comparator>::Heap(int maxNumber) 
	: maxSize{ maxNumber }
	, size{ 0 }
	, dataItems{ new DataType[maxNumber] }
{
}

template <typename DataType, typename KeyType, typename Comparator>
Heap<DataType, KeyType, Comparator>::Heap(const Heap& other) 
	: maxSize{ other->maxSize }
	, size{ other->size }
	, dataItems{ new DataType[other->maxSize] }
{
	std::copy(other->dataItems, other->dataItems + other->maxSize, dataItems);
}

template <typename DataType, typename KeyType, typename Comparator>
Heap<DataType, KeyType, Comparator>& Heap<DataType, KeyType, Comparator>::operator=(const Heap& other)
{
	// Self assignment check.
	if (this == &other) return *this;

	// Copy data.
	maxSize = other->maxSize;
	size = other->size;

	delete[] dataItems;
	dataItems = new DataType[maxSize];
	std::copy(other->dataItems, other->dataItems + other->maxSize, dataItems);

	return *this;
}

template <typename DataType, typename KeyType, typename Comparator>
Heap<DataType, KeyType, Comparator>::~Heap()
{
	delete[] dataItems;
}

template <typename DataType, typename KeyType, typename Comparator>
void Heap<DataType, KeyType, Comparator>::insert(const DataType& newDataItem) throw(std::logic_error)
{
	if (isFull())
	{
		throw std::logic_error("The heap is full.");
	}

	int hole = size++;
	
	// While the hole is not the top item 
	// and newDataItem has a priorty greater than or equal than the hole's parent.
	while(hole > 0 && comparator(dataItems[PARENT(hole)].getPriority(), newDataItem.getPriority()))
	{
		// Move the parent into the hole.
		dataItems[hole] = std::move(dataItems[PARENT(hole)]);

		// Set the parent to be the new hole.
		hole = PARENT(hole);
	}

	// Move the newDataItem into the final hole.
	dataItems[hole] = newDataItem;
}

template <typename DataType, typename KeyType, typename Comparator>
DataType Heap<DataType, KeyType, Comparator>::remove() throw(std::logic_error)
{
	if (isEmpty())
	{
		throw std::logic_error("The heap is empty.");
	}

	// Move the highest priority data item into our return variable.
	DataType ret = std::move(dataItems[0]);

	// Move the bottom right most data item into a temp variable.
	DataType temp = std::move(dataItems[--size]);

	// Heapify
	int hole = 0;

	// While hole has children
	while (LEFT(hole) < size)
	{
		// Set child to left child
		int child = LEFT(hole);

		// Does hole have a right child?
		if (child + 1 < size)
		{
			// Does right child have a greater priority than left child?
			if (comparator(dataItems[child].getPriority(), dataItems[child + 1].getPriority()))
			{
				// Set child to right child.
				child++;
			}
		}

		// Does the child have a greater than or equal priority than the temp DataType?
		if (comparator(temp.getPriority(), dataItems[child].getPriority()))
		{
			// Move the child DataType into the hole.
			dataItems[hole] = std::move(dataItems[child]);

			// Set the hole to be the child index.
			hole = child;
		}
		else
		{
			break;
		}
	}

	dataItems[hole] = std::move(temp);

	return ret;
}

template <typename DataType, typename KeyType, typename Comparator>
void Heap<DataType, KeyType, Comparator>::clear()
{
	delete[] dataItems;
	dataItems = new DataType[maxSize];
	size = 0;
}

template <typename DataType, typename KeyType, typename Comparator>
bool Heap<DataType, KeyType, Comparator>::isEmpty() const
{
	return size == 0;
}

template <typename DataType, typename KeyType, typename Comparator>
bool Heap<DataType, KeyType, Comparator>::isFull() const
{
	return size == maxSize;
}

template <typename DataType, typename KeyType, typename Comparator>
void Heap<DataType, KeyType, Comparator>::showStructure() const
{
	std::cout << std::endl;
	if (size == 0)
		std::cout << "Empty heap" << std::endl;
	else
	{
		// Output array form
		std::cout << "size = " << size << std::endl;
		for (int j = 0; j < maxSize; j++)
			std::cout << j << "\t";
		std::cout << std::endl;
		for (int j = 0; j < size; j++)
			std::cout << dataItems[j].getPriority() << "\t";
		std::cout << std::endl << std::endl;

		// Output tree form
		showSubtree(0, 0);                        
	}
}

template <typename DataType, typename KeyType, typename Comparator>
void Heap<DataType, KeyType, Comparator>::showSubtree(int index, int level) const
{
	if (index < size)
	{
		// Output right subtree
		showSubtree(RIGHT(index), level + 1);   
		
		// Tab over to level
		for (int j = 0; j < level; j++)        
			std::cout << "\t";

		// Output dataItems's priority
		std::cout << " " << dataItems[index].getPriority();
		
		// Output "connector"
		if (RIGHT(index) < size)                
			std::cout << "<";
		else if (LEFT(index) < size)
			std::cout << "\\";
		std::cout << std::endl;

		// Output left subtree
		showSubtree(LEFT(index), level + 1);        
	}
}