#include <string>
#include <vector>
#include <algorithm>
#include "not_url_char.h"
 
using std::string;
 
string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
  return find_if(b, e, not_url_char);
}