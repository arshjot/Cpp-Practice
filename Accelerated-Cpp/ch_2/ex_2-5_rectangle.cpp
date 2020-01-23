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
	cout << "Please enter number of rows for the rectangle: ";
	
	// read the rows
	int structRows;
	cin >> structRows;

	cout << "Please enter number of columns for the rectangle: ";
	
	// read the rows
	int structCols;
	cin >> structCols;
	
	// the number of rows and columns to write
	const int rows = structRows;
	const string::size_type cols = structCols;
	
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