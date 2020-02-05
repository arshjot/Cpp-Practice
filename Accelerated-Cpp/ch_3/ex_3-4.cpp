// Lengths of longest and shortest string in input

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;        using std::vector;
using std::cout;       using std::string;
using std::endl;       

int main()
{
	// ask for the words
	cout << "Enter multiple words one by one, "
	        "followed by end-of-file: ";

	int max_len = -1, min_len = -1, word_len;
	string s;

	while (cin >> s) {
		word_len = s.size();
		if (min_len == -1) {
			min_len = word_len;
			max_len = word_len;
		} else {
			if (word_len > max_len) {
				max_len = word_len;
			}
			if (word_len < min_len) {
				min_len = word_len;
			} 
		}
	}
	cout << endl;
	
	// check that atleast one word is entered
	if (min_len == -1) {
		cout << endl << "You must enter at least one word. "
		                "Please try again." << endl;
		return 1;
	}

	// print shortest and longest length
	cout << "Maximum word length = " << max_len << endl;
	cout << "Minimum word length = " << min_len << endl; 

	return 0;
}
