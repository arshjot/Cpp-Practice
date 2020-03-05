#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include "grade.h"
#include "Student_info.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::map;
 
// function to get letter grade classification
string get_letter_grade(double grade) {
    if (grade >= 90.0)
        return "A";
    if (grade >= 80.0)
        return "B";
    if (grade >= 70.0)
        return "C";
    if (grade >= 60.0)
        return "D";
    
    return "F";
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;   // the length of the longest name
    map<string, int> grouped_grade_count; // count of students for letter grades
 
    // read and store all the student's data.
    // Invariant:   students contain all the student records read so far
    //              maxlen contains the length of the longest name in students
    while (read(cin, record))
    {
        // find the length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
 
    // // alphabetize the student records
    // sort(students.begin(), students.end(), compare);
 
    // compute and store the counts by letter grades
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        //compute and write the grade
        try
        {
            double final_grade = grade(students[i]);
            grouped_grade_count[get_letter_grade(final_grade)]++;
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
    }

    // write the count for each letter grade
    cout << "Number of students with each letter grade:" << endl;
    for (map<string, int>::const_iterator it = grouped_grade_count.begin();
        it != grouped_grade_count.end(); ++it)
        cout << it->first << "\t" << it->second << endl;

    return 0;
}