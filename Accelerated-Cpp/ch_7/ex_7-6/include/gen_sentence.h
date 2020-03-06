#ifndef GUARD_GEN_SENTENCE_H
#define GUARD_GEN_SENTENCE_H

#include <vector>
#include <string>

#include "read_grammar.h"

void gen_aux(
	const Grammar&, const std::string&, std::vector<std::string>&,
	std::vector<std::string>&);
bool bracketed(const std::string&);
std::vector<std::string> gen_sentence(const Grammar&);

#endif // GUARD_GEN_SENTENCE_H