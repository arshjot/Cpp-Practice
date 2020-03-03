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
 
// two-pass solution to get failed students
// (S6.3.1)
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    remove_copy_if(students.begin(), students.end(),
        back_inserter(fail), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade),
    	students.end());
    return fail;
}