// §6.1.3 finding URLs in a string input
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "find_urls.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
 
int main()
{
    vector<string> urls;
    string s;

    cout << "Input a line to extract valid urls:" << endl;

    // read each line, extract the url/s and display them
    while (getline(cin, s)) {
        urls = find_urls(s);
        for (vector<string>::const_iterator iter = urls.begin();
             iter != urls.end(); ++iter)
            cout << (*iter) << endl;
    }

    return 0;
}
