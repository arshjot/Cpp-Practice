// Count how many times each distint word appears in input

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;        using std::vector;
using std::cout;       using std::string;
using std::endl;       using std::unique_copy;
using std::count;

int main()
{
	// ask for the words
	cout << "Enter multiple words one by one, "
	        "followed by end-of-file: ";

	vector<string> words;
	vector<string>::iterator it;
	string s;

	while (cin >> s)
		words.push_back(s);
	cout << endl;
	
	// check that atleast one word is entered
	typedef vector<double>::size_type vec_sz;
	vec_sz size = words.size();
	if (size == 0) {
		cout << endl << "You must enter at least one word. "
		                "Please try again." << endl;
		return 1;
	}

	// get unique elements
	vector<string> uniq_words(words.size());
	it = unique_copy(words.begin(), words.end(), uniq_words.begin());

	// resizing uniq_words
    uniq_words.resize(std::distance(uniq_words.begin(), it)); 
	
	// print frequency of each word
	for (it=uniq_words.begin(); it!=uniq_words.end(); ++it) {
		cout << "Element - " << *it << ": " 
		     << count(words.begin(), words.end(), *it)
		     << endl;
	}

	return 0;
}
