#include "Student_info.h"
#include "grade.h"
 
using std::istream;
using std::vector;
using std::cin;
 
// we are interested in sorting the Student_info object by the student's name
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}
 
// read student's name, midterm exam grade, final exam grade, and homework grades
// and store only the final calc grade in the Student_info object
istream& read(istream& is, Student_info& s)
{
    double midterm, final;
    std::vector<double> homework;

    // read and store the student's name and midterm and final exam grades
    is >> s.name >> midterm >> final;
 
    // read and store all the student's homework grades
    read_hw(is, homework);

    // calculate and store the final grade
    if (cin)
        s.final_grade = grade(midterm, final, homework);

    return is;
}
 
// read homework grades from an input stream into a vector<double>
// (as defined in S4.1.3/57)
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in)
    {
        // get rid of previous contents
        hw.clear();
 
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);
 
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}