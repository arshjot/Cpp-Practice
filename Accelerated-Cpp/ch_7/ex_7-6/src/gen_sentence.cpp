// had to refer to the solution given by the 
// author on github for this exercise :(
// below is simply the author's solution, 
// though it's a good one and we should understand the working
#include <string>
#include <vector>
#include <stdexcept>

#include "read_grammar.h"
#include "nrand.h"
 
using std::string;
using std::vector;
using std::logic_error;

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& token, 
	     vector<string>& sentence, vector<string>& tokens) {
	if (!bracketed(token)) {
		sentence.push_back(token);
	} else {
	// locate the rule that corresponds to `token'
	Grammar::const_iterator it = g.find(token);

	if (it == g.end())
		throw logic_error("empty rule");

	// fetch the set of possible rules
	const Rule_collection& c = it->second;

	// from which we select one at random
	const Rule& r = c[nrand(c.size())];

	// push rule's tokens onto stack of tokens
	// (in reverse order, because we're pushing and popping from the back)
	for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
		tokens.push_back(*i);
	}
}

vector<string> gen_sentence(const Grammar& g) {
	vector<string> sentence;
	vector<string> tokens;
	tokens.push_back("<sentence>");

	while (!tokens.empty()) {
		string token = tokens.back();
		tokens.pop_back();
		gen_aux(g, token, sentence, tokens);
	}

	return sentence;
}
