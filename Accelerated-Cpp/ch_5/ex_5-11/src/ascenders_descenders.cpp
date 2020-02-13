#include <string>
#include <vector>
#include <algorithm>
 
using std::string;
using std::vector;
using std::max;


bool has_ascenders(const string& v)
{
	for (string::const_iterator iter = v.begin();
        iter != v.end(); ++iter) {

        if (*iter == 'b' || *iter == 'd' || *iter == 'f' 
            || *iter == 'h' || *iter == 'k' || *iter == 'l' 
            || *iter == 't')
            return true;
    }

    return false;
}

bool has_descenders(const string& v)
{
    for (string::const_iterator iter = v.begin();
        iter != v.end(); ++iter) {

        if (*iter == 'g' || *iter == 'j' || *iter == 'p' 
            || *iter == 'q' || *iter == 'y')
            return true;
    }

    return false;
}

string longest_string(const vector<string>&v)
{
	string::size_type max_len = 0;
	string longest_s;

    // get the string with the maximum length
    for (vector<string>::const_iterator iter = v.begin();
        iter != v.end(); ++iter) {
        
        if (max_len < iter->length())
        	max_len = max(max_len, iter->length());
        	longest_s = *iter;
    }

    return longest_s;
}
