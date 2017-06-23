/*!@file
 * @author Joshua Forsyth
 * @date 03/30/17
 * @brief Class declaration for the array implementation of the Heap ADataType */

#pragma once

#include <stdexcept>
#include <iostream>

//! Decrementing comparator.
/*! @tparam KeyType The type of object to compare. */
template < typename KeyType=int >
class Less {
  public:
	//! Overloaded function operator. Gets the lesser of the two objects.
	/*! @param a A reference to the object that will be the left hand side of the comparison.
	 * @param[in] b A reference to the object that will be the right hand side of the comparison.
	 * @return A value indicating whether the first argument is less than the second.*/
    bool operator()(const KeyType &a, const KeyType &b) const { return a < b; }
};

//! Declaration of Heap ADT
/*! @tparam DataType The type of object that the heap will contain. 
 * @tparam KeyType The type of object used to represent the priority of an object.
 * @tparam The type of object to use to perform the priority comparison operation. */
template < typename DataType, typename KeyType=int, typename Comparator=Less<KeyType> >
class Heap
{
public:
	//! Default maximum heap size.
	static const int DEFAULT_MAX_HEAP_SIZE = 10; 

	//! Constructor. 
	/*! Creates an empty heap. Allocates enough memory for a heap containing maxNumber data items.
	* @param[in] maxNumber The maximum number of items that the heap will contain. */
    Heap ( int maxNumber = DEFAULT_MAX_HEAP_SIZE );

	//! Copy constructor. 
	/*! Initializes the object to be an equivalent copy of other.
	* @param[in] other A reference to another Heap that is being used to initialize this object. */
    Heap ( const Heap& other );

	//! Overloaded assignment operator. 
	/*! Sets the heap to be equivalent to the other Heap.
	* @param[in] other A reference to another Heap that values will be copied from.
	* @return A reference to this object. */
    Heap& operator= ( const Heap& other );  // Overloaded assignment operator

    //! Destructor. 
	/*! Deallocates (frees) memory used to store the heap. */
    ~Heap ();

	//! Inserts a new item into the heap. 
	/*! Inserts this data item as the bottom rightmost data item in the heap
	* and moves it upward until the properties that define a heap are restored.
	* @pre Heap is not full.
	* @exception std::logic_error The heap is full.
	* @param[in] newDataItem A reference to the object being added. */
	void insert(const DataType &newDataItem) throw (std::logic_error);

	//! Removes the data item with the highest priority (the root) from the heap. 
	/*! Replaces the root data with the bottom rightmost data item and moves this data item downward
	* until the properties that define a heap are restored.
	* @pre Heap is not empty.
	* @exception std::logic_error The heap is empty.
	* @return The removed data item. */
	DataType remove() throw (std::logic_error);

	//! Removes all the data items in the heap.
    void clear ();

	//! Heap is empty.
	/*! @return A value indicating whether the heap is empty. */
    bool isEmpty () const;

	//! Heap is full.
	/*! @return A value indicating whether the heap is full. */
    bool isFull () const;

	//! Outputs the priorities of the data items in the heap in both array and tree form.
	/*! The tree is output with its branches oriented from left (root) to right (leaves) --that is,
	* the tree is output rotated counterclockwise ninety degrees from its conventional orientation.
	* If the heap is empty, outputs "Empty heap." Note that this operation is intended for
	* testing/debugging purposes only. */
    void showStructure () const;

private:

	//! Helper function for the showStructure() function to output a subtree.
	/*! @param[in] index The index of the root of the subtree to output.
	* @param[in] level The level of this dataItem within the tree. */
	void showSubtree(int index, int level) const;

	// Maximum number of elements in the heap
	int maxSize;    

	// Actual number of elements in the heap
	int	size;		

	// Array containing the heap elements
    DataType *dataItems; 

	// Comparator to compare priorities
    Comparator comparator;
};
