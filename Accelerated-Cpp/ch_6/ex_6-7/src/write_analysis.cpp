#include <iostream>
#include <vector>
#include <string>
#include "Student_info.h"
#include "analysis.h"
 
using std::ostream;
using std::endl;
using std::string;
using std::vector;
 
// function to output the results for students
// who did and didn't do all of their homework.
// (S6.2.3)
void write_analysis(ostream& out,
                    const string& name,
                    double grade_fn(const Student_info&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did, grade_fn) <<
				   ": median(didnt) = " << analysis(didnt, grade_fn) << endl;
}