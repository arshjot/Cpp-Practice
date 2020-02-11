#include "Student_info.h"
#include "grade.h"
#include <vector>
 
using std::vector; 

// predicate to determine whether a student failed
// (S5.1/75)
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// check if a student failed using an iterator
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;
    vector<Student_info>::size_type init_size = students.size();
    
    while (i != students.size())
    {
        if (fgrade(students[i]))
            fail.push_back(students[i]);
        else {
            students.insert(students.begin(), students[i]);
            ++i;
        }
        ++i;
    }

    students.resize(init_size - fail.size());

    return fail;
} 