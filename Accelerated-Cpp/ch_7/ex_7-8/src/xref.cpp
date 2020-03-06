#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

#include "split.h"
 
using std::string;
using std::vector;
using std::map;
using std::istream;

// find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in,
	vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	// read the next line
	while (getline(in, line)) {
		++line_number;
	
		// break the input line into words
		vector<string> words = find_words(line);
	
		// remember that each word occurs on the current line
		for (vector<string>::const_iterator it = words.begin();
				it != words.end(); ++it) {

			// check if it is first occurence of the word in this line
			if (find(ret[*it].begin(), ret[*it].end(), line_number) 
				== ret[*it].end())
				ret[*it].push_back(line_number);

		}
	}
	return ret;
}