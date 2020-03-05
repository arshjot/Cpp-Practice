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

void gen_aux(
	const Grammar& g, const string& word, vector<string>& ret)
{
	if (!bracketed(word)) {
		ret.push_back(word);
	} else {
		// locate the rule that corresponds to word
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");
		
		// fetch the set of possible rules
		const Rule_collection& c = it->second;
		
		// from which we select one at random
		const Rule& r = c[nrand(c.size())];
		
		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}
}

vector<string> gen_sentence(const Grammar& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}
