#include <string>
#include <vector>
#include <algorithm>
 
using std::string;
using std::vector;
using std::max;
 
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::const_iterator iter = v.begin();
                iter != v.end(); ++iter)
        maxlen = max(maxlen, (*iter).size());
    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
 
    // write the top border
    ret.push_back(border);
 
    // write each interior row, bordered by an asterisk and a space
    for(vector<string>::const_iterator iter = v.begin();
                iter != v.end(); ++iter)
        ret.push_back("* " + (*iter) + string(
            maxlen - (*iter).size(), ' ') + " *");
 
    // write the bottom border
    ret.push_back(border);
 
    return ret;
}
