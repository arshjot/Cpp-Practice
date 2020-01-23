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
	cout << "Please enter number of rows for the square: ";
	
	// read the size
	int structSize;
	cin >> structSize;
	
	// the number of rows and columns to write
	const int rows = structSize;
	const string::size_type cols = structSize;
	
	// write a blank line to separate the output from the input
	cout << endl;
	
	// write rows of output
	// invariant: we have written r rows so far
	for (int r = 0; r != rows; ++r) {
	
		string::size_type c = 0;
		
		// invariant: we have written c characters so far in the current row
		while (c != cols) {
			cout << "*";
			c++;
		}		
		cout << endl;
	}	
	return 0;
}