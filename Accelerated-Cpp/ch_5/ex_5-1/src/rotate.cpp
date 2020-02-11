#include <string>
#include <vector>
#include <numeric>
#include "rotate.h"
#include "split.h"

using std::string;
using std::accumulate;
using std::vector;
using std::copy;

// function to define the comparison of splitted strings
// comparison to be done in lowercase
bool compare(const Rotated_line& x, const Rotated_line& y)
{
    return x.second_half < y.second_half;
}

vector<Rotated_line> rotate(const vector<string>& lines)
{
	vector<string> line;
	vector<Rotated_line> rot_lines;

	// Loop over all the lines
	for (vector<string>::size_type li=0; li!=lines.size(); ++li) {
		
		// Split the line into words
		line = split(lines[li]);

		// Rotate the line and split each instance into two halves
		for (vector<string>::size_type wi=0; wi!=line.size(); ++wi) {

			Rotated_line rot;
			rot.first_half.insert(rot.first_half.begin(), line.begin(), line.begin() + wi);
			rot.second_half.insert(rot.second_half.begin(), line.begin() + wi, line.end());

			rot_lines.push_back(rot);
		}
	}

	return rot_lines;
}
