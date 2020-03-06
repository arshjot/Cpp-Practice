// had to refer to the solution given by the 
// author on github for this exercise :(
// below is simply the author's solution, 
// though it's a good one and we should understand the working
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>

#include "gen_sentence.h"
#include "time.h"
 
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;

int main() {
	srand(time(NULL));
	// generate the sentence
	vector<string> sentence = gen_sentence(read_grammar(cin));
	
	// write the first word, if any
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		cout << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while (it != sentence.end()) {
		cout << " " << *it;
		++it;
	}
	cout << endl;
	return 0;
}