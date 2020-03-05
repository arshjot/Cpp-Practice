// §7.4 Generating sentences
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "gen_sentence.h"
 
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;

int main() {
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