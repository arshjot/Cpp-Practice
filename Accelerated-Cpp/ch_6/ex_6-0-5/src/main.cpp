// §6.3.1 use a two-pass algorithmic solution 
// for extracting failed students
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>

#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::sort;
using std::string;
using std::vector;
using std::setprecision;
using std::streamsize;
using std::fixed;
 
int main()
{
    vector<Student_info> students;
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
    vector<Student_info> students_failed = extract_fails(students);
    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;

    streamsize prec = cout.precision();
    cout << "Time elapsed = "  << fixed
         << elapsed_secs << " seconds" 
         << setprecision(prec) << endl;

    return 0;
}
