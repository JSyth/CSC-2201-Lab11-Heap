/*!@file
* @author Joshua Forsyth
* @date 03/30/17
* @brief Declaration of TaskData struct */

#pragma once
#include "TaskPriority.h"

//! Definition of the task data struct.
struct TaskData
{
	//! Returns the priority. Required by the Heap ADT.
	/*! @return The object that represents the priority of the task. */
	TaskPriority getPriority() const;

	//! Stores the priority and arrived time of the TaskData object.
	TaskPriority priority;
};