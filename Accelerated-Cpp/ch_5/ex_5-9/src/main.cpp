#include <iostream>
#include <vector>
#include <string>
#include "word_case.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
 
int main()
{
    string s;
    vector<string> lowercase, uppercase;
 
    while (cin >> s) {
        if (has_uppercase(s))
            uppercase.push_back(s);
        else
            lowercase.push_back(s);
    }
 
    // print lowercase words followed by uppercase ones
    cout << endl << "Lowercase words: " << endl;
    for (vector<string>::const_iterator iter = lowercase.begin();
         iter != lowercase.end(); ++iter)
        cout << (*iter) << endl;
    cout << endl << "Uppercase words: " << endl;
    for (vector<string>::const_iterator iter = uppercase.begin();
         iter != uppercase.end(); ++iter)
        cout << (*iter) << endl;
 
    return 0;
}
