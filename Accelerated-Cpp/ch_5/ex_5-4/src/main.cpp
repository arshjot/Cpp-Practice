#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <list>

#include "grade.h"
#include "Student_info.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::sort;
using std::string;
using std::vector;
using std::list;
using std::setprecision;
using std::streamsize;
using std::fixed;
 
// change below line to switch between
// a vector-based or a list-based solution
typedef list<Student_info> Student_info_struct;
// typedef vector<Student_info> Student_info_struct;


// check if a student failed using an iterator
Student_info_struct extract_fails(Student_info_struct& students)
{
    Student_info_struct fail;
    Student_info_struct::iterator iter = students.begin();
    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
} 


int main()
{
    Student_info_struct students;
    Student_info record;
    string::size_type maxlen = 0;   // the length of the longest name
 
    // read and store all the student's data.
    // Invariant:   students contain all the student records read so far
    //              maxlen contains the length of the longest name in students
    while (read(cin, record))
    {
        // find the length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
 
    // Determine failed students and the processsing time taken
    clock_t start = clock();
    Student_info_struct students_failed = extract_fails(students);
    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;

    streamsize prec = cout.precision();
    cout << "Time elapsed = "  << fixed
         << elapsed_secs << " seconds" 
         << setprecision(prec) << endl;

    return 0;
}