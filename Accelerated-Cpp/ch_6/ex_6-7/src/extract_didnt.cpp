#include <vector>
#include <algorithm>

#include "Student_info.h"
 
using std::vector; 

bool did_all_hw(const Student_info& s)
{
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

// single-pass solution to get students who didnt do homework
vector<Student_info> extract_didnt(vector<Student_info>& students)
{
	vector<Student_info>::iterator iter =
		stable_partition(students.begin(), students.end(), did_all_hw);

	vector<Student_info> didnt(iter, students.end());
	students.erase(iter, students.end());

	return didnt;
}