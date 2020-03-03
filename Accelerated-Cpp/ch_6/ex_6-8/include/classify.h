#ifndef GUARD_CLASSIFY_H
#define GUARD_CLASSIFY_H
 
// extract_didnt.h
#include <vector>
#include "Student_info.h"

std::vector<Student_info> classify(std::vector<Student_info>&, 
	bool criteria(const Student_info&));

#endif // GUARD_CLASSIFY_H