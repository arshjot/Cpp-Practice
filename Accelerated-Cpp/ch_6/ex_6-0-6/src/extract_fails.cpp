#include <vector>
#include <algorithm>

#include "Student_info.h"
#include "grade.h"
 
using std::vector; 

// predicate to determine whether a student failed
// (S5.1/75)
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// predicate to determine whether a student passed
// (S6.3.1)
bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}
 
// single-pass solution to get failed students
// (S6.3.2)
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info>::iterator iter =
		stable_partition(students.begin(), students.end(), pgrade);

	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());

	return fail;
}