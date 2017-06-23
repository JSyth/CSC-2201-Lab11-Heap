/*!@file
 * @author Joshua Forsyth
 * @date 03/30/17
 * @brief Struct declaration for TaskPriority */

#pragma once

//! Declaration of custom task priorty struct.
/*! Prioritizes by explicit priorty then by arrived time. */
struct TaskPriority
{
	//! Int conversion function.
	/*! @return The major priority of the task.*/
	operator int() const;

	//! Overloaded less than operator.
	/*! If priorities are equal, the lesser TaskPriority will have the greater arrived value. 
	 * @param[in] rhs A reference to the right hand side of the operator.
	 * @return A value indicating whether this is less than the argument. */
	bool operator <(const TaskPriority &rhs) const;

	//! Overloaded greater than operator.
	/*! If priorties are equal, the greater TaskPriorty will have lesser arrived value. 
	 * @param[in] rhs A reference to the right hand side of the operator.
	 * @return A value indicating whether this is greater than the argument. */
	bool operator >(const TaskPriority &rhs) const;

	//! The major priority of the task.
	int major;

	//! The time that the task arrived in the collection
	/*! Used when comparing priorities if the major priorities are equal.*/
	int arrived;

};