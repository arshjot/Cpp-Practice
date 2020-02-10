#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// function to read and store words in a vector
istream& read_words(istream& in, vector<string>& words) {
	if (in) {
		words.clear();
		string word;

		while (in >> word)
			words.push_back(word);
		in.clear();
	}
	return in;
}

int main()
{
	vector<string> words;
	vector<string>::iterator it;
	read_words(cin, words);

	cout << "Number of words = " << words.size() << endl;

	// get unique elements
	vector<string> uniq_words(words.size());
	it = std::unique_copy(words.begin(), words.end(), uniq_words.begin());

	// resizing uniq_words
    uniq_words.resize(std::distance(uniq_words.begin(), it)); 
	
	// print frequency of each word
	for (it=uniq_words.begin(); it!=uniq_words.end(); ++it) {
		cout << "Frequency of " << *it << " = " 
		     << count(words.begin(), words.end(), *it)
		     << endl;
	}
	
	return 0;
}
