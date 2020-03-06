#ifndef GUARD_XREF_H
#define GUARD_XREF_H

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "split.h"

std::map<std::string, std::vector<int> > xref(std::istream&,
	std::vector<std::string> find_words(const std::string&) = split);

#endif // GUARD_XREF_H