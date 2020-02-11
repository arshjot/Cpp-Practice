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
    
    while (i != students.size())
    {
        if (fgrade(students[i]))
        {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        else
            ++ i;
    }
    return fail;
} 