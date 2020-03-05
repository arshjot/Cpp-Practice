// Group words by occurence count
#include <iostream>
#include <string>
#include <map>
#include <vector>
 
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;

int main()
{
	string s;
	map<string, int> counters;	// store each word and an associated counter
	map<int, vector<string>> word_freq;

	// read the input, keeping track of each word and how often we see it
	while (cin >> s)
		++counters[s];

	// group words by frequency
	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); ++it)
		word_freq[it->second].push_back(it->first);
	
	// write the frequencies and its associated words
	for (map<int, vector<string>>::const_iterator f_it = word_freq.begin();
		f_it != word_freq.end(); ++f_it) {
		cout << "\nFrequency: " << f_it->first << endl;

		for (vector<string>::const_iterator w_it = f_it->second.begin();
			w_it != f_it->second.end(); ++w_it)
			cout << (*w_it) << endl;
	}
	return 0;
}