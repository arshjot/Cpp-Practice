#include <iostream>
#include <string>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;
 

// function to center a picture
vector<string> center(const vector<string>& orig_pic) {

	vector<string> padded_pic;
	string::size_type max_len = 0;

	// get maximum length
	for (vector<string>::const_iterator i = orig_pic.begin();
		i != orig_pic.end(); ++i)
		max_len = max(max_len, i->size());

	// create padded pic
	for (vector<string>::const_iterator i = orig_pic.begin();
		i != orig_pic.end(); ++i) {

	// pad size to be half of the total padding required 
	// to center the pic
	vector<string>::size_type pad_size = (max_len - i->size()) / 2;
	
	string new_line(pad_size, ' ');
	new_line += *i;
	padded_pic.push_back(new_line);
	}

	return padded_pic;
}


int main() 
{
    vector<string> orig_pic, centered_pic;
    string s;

    // read each line of input and get maximum line length
    while (getline(cin, s))
        orig_pic.push_back(s);

    centered_pic = center(orig_pic);

    cout << endl;
    for (vector<string>::const_iterator i = centered_pic.begin();
		i != centered_pic.end(); ++i)
		cout << *i << endl;

	return 0;
}
