#include <vector>
#include <algorithm>

#include "Student_info.h"
 
using std::vector; 

// single-pass solution to get students who didnt do homework
vector<Student_info> classify(vector<Student_info>& students,
	bool criteria(const Student_info&))
{
	vector<Student_info>::iterator iter =
		stable_partition(students.begin(), students.end(), criteria);

	vector<Student_info> didnt(iter, students.end());
	students.erase(iter, students.end());

	return didnt;
}