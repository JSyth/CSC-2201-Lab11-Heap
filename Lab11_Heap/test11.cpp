/*! @file
 * @author Joshua Forsyth
 * @date 03/30/17
 * @brief Test program for the operations in the Heap ADT */


#include <iostream>
#include <string>
#include <cctype>
#include "Heap.cpp"
#include "config.h"



//--------------------------------------------------------------------
// Prototypes

void printHelp();

//! Declaration for the heap data item class
/*! @tparam KeyType The type of object used to represent the priority of the data item. */
template < typename KeyType >
class TestDataItem
{
public:
	//! Constructor. 
	/*! Initializes priority to -1;*/
    TestDataItem ()
    {
	    priority = -1;
    }

	//! Set the priority.
    void setPriority ( KeyType  newPty )
    {
	    priority = newPty;
    }

	//! Get the priority.
    KeyType  getPriority () const
    {
	    return priority;
    }

private:
	// Priority for the data item
    KeyType  priority;                    
};

//! Incrementing comparator.
/*! @tparam KeyType The type of object to compare. */
template < typename KeyType=int >
class Greater {
  public:
	  //! Overloaded function operator. Gets the greater of the two objects.
	  /*! @param a A reference to the object that will be the left hand side of the comparison.
	  * @param b A reference to the object that will be the right hand side of the comparison.
	  * @return A value indicating whether the first argument is greater than the second.*/
    bool operator()( const KeyType &a, const KeyType &b) const { return a > b; }
};

#if !LAB11_PROGRAM1
//! Main entry point for Heap test program.
int main()
{
    // Greater<> uses the default int type for its KeyType
	// Test heap
    Heap<TestDataItem<int>, int, Greater<> > testHeap(8);  

	// Heap data item
    TestDataItem<int> testDataItem;   
	
	// User input priority
    int  inputPty;   
	
	// Input command
    char cmd;                             

    printHelp();

    do
    {
		// Output heap
        testHeap.showStructure();                     

		// Read command
	    std::cout << std::endl << "Command: ";                  
	    std::cin >> cmd;

		// Upcase input
		cmd = toupper(cmd);
        if ( cmd == '+' )
	        std::cin >> inputPty;

		switch (cmd)
		{
		// print help
		case 'H':
			printHelp();
			break;

		// insert  
		case '+':
			testDataItem.setPriority(inputPty);
			std::cout << "Insert : priority = " << testDataItem.getPriority()
				<< std::endl;
			try
			{
				testHeap.insert(testDataItem);
			}
			catch (std::logic_error e)
			{
				std::cout << e.what() << std::endl;
			}

			break;

		// remove
		case '-':
			try
			{
				testDataItem = testHeap.remove();
				std::cout << "Removed data item : "
					<< " priority = " << testDataItem.getPriority() << std::endl;
			}
			catch (std::logic_error e)
			{
				std::cout << e.what() << std::endl;
			}

			break;

		// clear
		case 'C':
			std::cout << "Clear the heap" << std::endl;
			testHeap.clear();
			break;

		// isEmpty
		case 'E':
			if (testHeap.isEmpty())
				std::cout << "Heap is empty" << std::endl;
			else
				std::cout << "Heap is NOT empty" << std::endl;
			break;

			// isFull
		case 'F':
			if (testHeap.isFull())
				std::cout << "Heap is full" << std::endl;
			else
				std::cout << "Heap is NOT full" << std::endl;
			break;

		// Quit test program
		case 'Q':
			break;

		// Invalid command
		default:
			std::cout << "Inactive or invalid command" << std::endl;
		}
    }
    while ( cmd != 'Q' );

    return 0;
}
#endif
//--------------------------------------------------------------------

//! Prints the valid commands for the heap test program.
void printHelp()
{
	std::cout << std::endl << "Commands:" << std::endl;
	std::cout << "  H    : Help (displays this message)" << std::endl;
	std::cout << "  +pty : Insert data item with priority pty" << std::endl;
	std::cout << "  -    : Remove highest priority data item" << std::endl;
	std::cout << "  C    : Clear the heap" << std::endl;
	std::cout << "  E    : Empty heap?" << std::endl;
	std::cout << "  F    : Full heap?" << std::endl;
	std::cout << "  Q    : Quit the test program" << std::endl;
	std::cout << std::endl;
}

