#include <string>
#include <vector>
#include "frame.h"
 
using std::string;
using std::vector;
 
vector<string> hcat(const vector<string>& left, 
    const vector<string>& right)
{
    vector<string> ret;
 
    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;
 
    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;
 
    // EX-5-8: If s is declared outside the while loop in hcat.cpp
    // we get a length_error as width1 - s.size() becomes negative.
    // We can avoid this by clearing the string at the beginning 
    // of each while loop

    // construct new string to hold characters from both pictures
    string s;
 
    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size())
    {
        // clear previous loop's string
        // if below line is removed we'll get an error due to -ve length
        s.clear();

        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];
 
        // pad to full width
        s += string(width1 - s.size(), ' ');
 
        // copy a row from teh right-hand side, if there is one
        if (j != right.size())
            s += right[j++];
 
        // add s to the picture we are creating
        ret.push_back(s);
    }
 
    return ret;
}
