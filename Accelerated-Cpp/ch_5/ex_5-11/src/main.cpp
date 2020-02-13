#include <iostream>
#include <vector>
#include <string>
#include "ascenders_descenders.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
 
int main()
{
    string s;
    vector<string> ascenders, descenders, no_asc_desc;
    bool has_asc_or_desc;
 
    while (cin >> s) {
        has_asc_or_desc = false;
        if (has_ascenders(s)) {
            ascenders.push_back(s);
            has_asc_or_desc = true;
        }
        if (has_descenders(s)) {
            descenders.push_back(s);
            has_asc_or_desc = true;
        }
        if (!has_asc_or_desc)
            no_asc_desc.push_back(s);
    }
 
    // print words with ascenders and descenders
    if (ascenders.size() != 0) {
        cout << endl << "Words with ascenders: " << endl;
        for (vector<string>::const_iterator iter = ascenders.begin();
             iter != ascenders.end(); ++iter)
            cout << (*iter) << endl;
    }
    else
        cout << endl << "No words with ascenders found" << endl;

    if (descenders.size() != 0) {
        cout << endl << "Words with descenders: " << endl;
        for (vector<string>::const_iterator iter = descenders.begin();
             iter != descenders.end(); ++iter)
            cout << (*iter) << endl;
    }
    else
        cout << endl << "No words with descenders found" << endl;

    // print longest word without any ascenders or descenders
    if (no_asc_desc.size() != 0) {
        cout << endl << "Longest word without ascenders/descenders: " << endl;
        cout << longest_string(no_asc_desc) << endl;
    }
    else
        cout << endl << "No word without ascenders/descenders found" << endl;
 
    return 0;
}
