#ifndef GUARD_GEN_SENTENCE_H
#define GUARD_GEN_SENTENCE_H

#include <list>
#include <string>

#include "read_grammar.h"

void gen_aux(
	const Grammar&, const std::string&, std::list<std::string>&);
bool bracketed(const std::string&);
std::list<std::string> gen_sentence(const Grammar&);

#endif // GUARD_GEN_SENTENCE_H