// Use iterators in frame.cpp and hcat.cpp
#include <iostream>
#include <vector>
#include <string>
#include "hcat.h"
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