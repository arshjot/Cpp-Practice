#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
 
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

bool is_palindrome(const string& v)
{
	string inp_s = lowercase_string(v);
	string reverse_s(inp_s);
	reverse(reverse_s.begin(), reverse_s.end());

	if (inp_s == reverse_s)
		return true;
	else
		return false;
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

