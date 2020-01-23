#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;
using std::endl;
using std::cout;
using std::string;

int main()
{
	// ask for the size of the structure
	cout << "Please enter number of rows for the triangle: ";
	
	// read the size
	int structSize;
	cin >> structSize;
	
	// the number of rows and columns to write
	const int rows = structSize;
	// number of columns has to be odd 
	// to create an equilateral triangle
	const string::size_type cols = 2*structSize+1;
	
	// write a blank line to separate the output from the input
	cout << endl;
	
	// write rows of output
	// invariant: we have written r rows so far
	for (int r = 0; r != rows; ++r) {
	
		string::size_type c = 0;
		
		// preceding blank pad
		cout << string(cols - rows - r - 1, ' ');

		// triangle *
		cout << string(2*r + 1, '*');

		// succeeding blank pad
		cout << string(cols - rows - r - 1, ' ');

		cout << endl;
	}	
	return 0;
}