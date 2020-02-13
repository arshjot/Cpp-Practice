#include <string>
#include <cctype>
 
using std::string;
using std::isupper;
 
bool has_uppercase(const string& v)
{
    bool has_upper = false;
 
    // check if the input word has any uppercase character
    for (string::const_iterator iter = v.begin();
        iter != v.end(); ++iter)
        if (isupper(*iter)) {
            has_upper = true;
            break;
        }
 
    return has_upper;
}
