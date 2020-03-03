// source file for the average, average grade 
// and average analysis functions
#include <vector>
#include <numeric>
#include <algorithm>

#include "Student_info.h"
#include "grade.h"
#include "median.h"

using std::vector;
using std::accumulate;
using std::transform;
 
// compute average of elements
double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
 
// compute the final grade using average instead of median
double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}
