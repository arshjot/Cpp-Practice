// §6.1.1 Split line into words using library algorithms
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "split.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
 
int main()
{
    vector<string> words;
    string s;

    // read each line, split it and display
    while (getline(cin, s)) {
        words = split(s);
        for (vector<string>::const_iterator iter = words.begin();
             iter != words.end(); ++iter)
            cout << (*iter) << endl;
    }

    return 0;
}
