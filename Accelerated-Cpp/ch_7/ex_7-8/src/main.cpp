// find all the urls
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

#include "xref.h"
#include "find_urls.h"
 
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::ostringstream;

#define LINE_LENGTH 72

int main()
{
	// call xref using split by default
	map<string, vector<int> > ret = xref(cin, find_urls);

	// write the results
	cout << endl;
	for (map<string, vector<int> >::const_iterator it = ret.begin();
		it != ret.end(); ++it) {

		ostringstream out_stream;
	
		// write the word
		if (it->second.size() == 1) {
			out_stream << it->first << " occurs on line: ";
		} else {
			out_stream << it->first << " occurs on lines: ";
		}
	
		// followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		out_stream << *line_it; // write the first line number

		++line_it;
		// write the rest of the line numbers, if any
		while (line_it != it->second.end()) {
			out_stream << ", " << *line_it;
			++line_it;
		}

		// insert new line if width increases line_length
		string out_line = out_stream.str();
	    for (string::size_type i = 0; i != out_line.size(); ++i ) {
			if ((i + 1) % LINE_LENGTH == 0)
				cout << endl;
			cout << out_line[i];
	    }

		// write a new line to separate each word from the next
		cout << endl;
	}
	return 0;
}