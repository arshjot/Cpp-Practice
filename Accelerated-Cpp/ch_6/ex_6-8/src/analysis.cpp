#include <vector>
#include <algorithm>
#include "Student_info.h"

#include "grade.h"
#include "median.h"
 
using std::vector;
 
double analysis(
	const vector<Student_info>& students, 
	double grade_fn(const Student_info&))
{
	vector<double> grades;

	transform(students.begin(), students.end(), 
		back_inserter(grades), grade_fn);
	return median(grades);
}