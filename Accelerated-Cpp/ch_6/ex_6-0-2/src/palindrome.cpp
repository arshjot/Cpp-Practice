#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iostream>
 
using std::string;
using std::tolower;
using std::reverse;
using std::vector;
using std::max;


string lowercase_string(const string& v)
{
	string lower_s;
    
    // Turn the string into lowercase
    for (string::const_iterator iter = v.begin();
        iter != v.end(); ++iter)
        lower_s.push_back(tolower(*iter));
 
    return lower_s;
}

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

string longest_string(const vector<string>&v)
{
	string longest_s;

    // get the string with the maximum length
    for (vector<string>::const_iterator iter = v.begin();
        iter != v.end(); ++iter) {
        
        if (iter->length() > longest_s.length())
        	longest_s = *iter;
    }

    return longest_s;
}
