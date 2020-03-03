// §6.2 comparing grade schemes
#include <iostream>
#include <vector>

#include "grade.h"
#include "extract_didnt.h"
#include "Student_info.h"
#include "median.h"
#include "optimistic_median.h"
#include "average.h"
#include "write_analysis.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
 
int main()
{
    vector<Student_info> did, didnt;
    Student_info student;

    // read all the records, separating them based on whether all homework was done
    while (read(cin, student)) {
        did.push_back(student);
    }

    didnt = extract_didnt(did);

    // check that both groups contain data
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    // do the analyses
    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in",
        optimistic_median, did, didnt);

    return 0;
}
