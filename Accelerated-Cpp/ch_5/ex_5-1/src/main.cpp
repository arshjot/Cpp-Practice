#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "rotate.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::max;
 
int main() 
{
    vector<string> lines, first_half, second_half;
    vector<Rotated_line> rot_lines;
    string s, first_s, second_s;
    string::size_type max_len = 0;

    // read each line of input and get maximum line length
    while (getline(cin, s)) {
        lines.push_back(s);
        max_len = max(max_len, s.length());
    }

    // step 1: rotate and separate the first and second halves of each line
    rot_lines = rotate(lines);

    // step 2: sort the split lines
    sort(rot_lines.begin(), rot_lines.end(), compare);

    // step 3: Print the sorted lines (permuted index) in proper format
    cout << endl;
    for (vector<Rotated_line>::size_type i=0; i!=rot_lines.size(); ++i) {

        first_s.clear();
        second_s.clear();
        first_half = rot_lines[i].first_half;
        second_half = rot_lines[i].second_half;

        // concatenate string vectors using space as delimiter
        for (vector<string>::size_type j=0; j!=first_half.size(); ++j)
            first_s += first_half[j] + ' ';
        for (vector<string>::size_type j=0; j!=second_half.size(); ++j)
            second_s += second_half[j] + ' ';

         // remove extra space at the end
        if (first_s.size() != 0) first_s.pop_back();
        if (second_s.size() != 0) second_s.pop_back();

        cout << setw(max_len)
             << first_s << "\t"
             << second_s << endl;
    }

    return 0;
}
