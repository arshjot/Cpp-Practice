// If s is declared outside the while loop in hcat.cpp
// we get a length_error as width1 - s.size() becomes negative.
// We can avoid this by clearing the string at the beginning of each loop

#include <iostream>
#include <vector>
#include <string>
#include "hcat.h"
#include "vcat.h"
#include "frame.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
 
int main()
{
    string s;
    vector<string> p;
 
    // read multiple lines to make a paragraph
    while (getline(cin, s))
        p.push_back(s);
 
    // Horizontally concatenate p and framed p and display the result
    vector<string> out = hcat(p, frame(p));

    for (vector<string>::const_iterator iter = out.begin();
         iter != out.end(); ++iter)
    {
        cout << (*iter) << endl;
    }
 
    return 0;
}