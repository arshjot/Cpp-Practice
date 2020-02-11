#ifndef GUARD_EXTRACT_FAILS_H
#define GUARD_EXTRACT_FAILS_H
 
// extract_fails.h
#include <vector>
#include "Student_info.h"

bool fgrade(const Student_info&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
 
#endif // GUARD_EXTRACT_FAILS_H