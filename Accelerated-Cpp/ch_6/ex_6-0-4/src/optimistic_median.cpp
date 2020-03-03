// source file for the optimistic median and its analysis functions
#include <vector>
#include <algorithm>
#include "Student_info.h"

#include "grade.h"
#include "median.h"
 
using std::vector;
 
// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(),
		back_inserter(nonzero), 0);
	
	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(
	const vector<Student_info>& students)
{
  vector<double> grades;

  transform(students.begin(), students.end(), 
  	back_inserter(grades), optimistic_median);
  return median(grades);
}