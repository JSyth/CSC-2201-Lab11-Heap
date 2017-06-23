/*!@file
* @author Joshua Forsyth
* @date 03/30/17
* @brief Laboratory 11 Programming Exercise 1
* @details (Shell) Operating system task scheduling simulation.
* Simulates an operating system's use of a priority queue to regulate
* access to a system resource (print, disk, etc.). */

#include <iostream>
#include <cstdlib>
#include "PriorityQueue.cpp"
#include "config.h"
#include <ctime>
#include "TaskData.h"

#if LAB11_PROGRAM1
//! Main entry point for task scheduler program.
int main ()
{
	// Priority queue of tasks
    PriorityQueue<TaskData, TaskPriority, Less<>> taskPQ;  

	// Length of simulation (minutes)
	int simLength;     
	
	// Number of priority levels
	int	numPtyLevels;           

	std::cout << std::endl << "Enter the number of priority levels : ";
	std::cin >> numPtyLevels;

	// Array to store the longest waits for each priorty level.
	int* longestWaits = new int[numPtyLevels];
	for (int i = 0; i < numPtyLevels; i++)
		longestWaits[i] = INT_MIN;

	std::cout << "Enter the length of time to run the simulator : ";
	std::cin >> simLength;

	// Seed the random number generator
	srand(static_cast<unsigned int>(time(nullptr)));

	// While the simulation is not done.
    for ( int minute = 0 ; minute < simLength ; minute++ )
    {
		// Does the queue contain any tasks?
		if (!taskPQ.isEmpty())
		{
			TaskData task = taskPQ.dequeue();
			int wait = minute - task.priority.arrived;
			std::cout << "Task dequeued:";
			std::cout << " Priority = " << task.priority;
			std::cout << ", Arrived = " << task.priority.arrived;
			std::cout << ", Time in Queue = " << wait << std::endl;

			if (wait > longestWaits[task.priority])
				longestWaits[task.priority] = wait;
		}

		// Compute a random number between 0 and 3.
		int numArrivals = rand() % 4;

		// If numArrivals is one or two, add a task for each numArrival.
		if (numArrivals == 1 || numArrivals == 2)
		{
			for (int i = 0; i < numArrivals; i++)
			{
				TaskData task = { {rand() % numPtyLevels, minute} };
				taskPQ.enqueue(task);
			}
		}
    }

	// Print longest waits
	std::cout << std::endl << "Longest Waits:" << std::endl;
	for (int i = 0; i < numPtyLevels; i++)
		std::cout << "Priority " << i << " = " << longestWaits[i] << std::endl;

    return 0;
}
#endif

