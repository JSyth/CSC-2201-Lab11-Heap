/*!@file
* @author Joshua Forsyth
* @date 03/30/17
* @brief Implementation of TaskPriority struct
*/

#include "TaskPriority.h"

TaskPriority::operator int() const
{
	return major;
}

bool TaskPriority::operator<(const TaskPriority& rhs) const
{
	return major == rhs.major ? arrived > rhs.arrived : major < rhs.major;
}

bool TaskPriority::operator>(const TaskPriority& rhs) const
{
	return major == rhs.major ? arrived < rhs.arrived : major > rhs.major;
}
