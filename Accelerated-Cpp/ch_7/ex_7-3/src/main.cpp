// §7.3 Generating a cross-reference table - Improved
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "xref.h"
 
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;

int main()
{
	// call xref using split by default
	map<string, vector<int> > ret = xref(cin);

	// write the results
	cout << endl;
	for (map<string, vector<int> >::const_iterator it = ret.begin();
		it != ret.end(); ++it) {
	
		// write the word
		cout << it->first << " occurs on line(s): ";
	
		// followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it; // write the first line number

		++line_it;
		// write the rest of the line numbers, if any
		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}

		// write a new line to separate each word from the next
		cout << endl;
	}
	return 0;
}