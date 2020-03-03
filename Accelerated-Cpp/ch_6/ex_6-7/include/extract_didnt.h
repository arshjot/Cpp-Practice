#ifndef GUARD_EXTRACT_DIDNT_H
#define GUARD_EXTRACT_DIDNT_H
 
// extract_didnt.h
#include <vector>
#include "Student_info.h"

bool did_all_hw(const Student_info&);
std::vector<Student_info> extract_didnt(std::vector<Student_info>&);

#endif // GUARD_EXTRACT_DIDNT_H