// re-implement nrand.cpp to handle integers 
// greater than RAND_MAX as well
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>

#include "nrand.h"
#include "time.h"
 
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;

#define MY_RAND_MAX 10 // change it in nrand.cpp file as well

int main() {
	srand(time(NULL));
	
	cout << "\nMY_RAND_MAX = " << MY_RAND_MAX << endl;
	cout << "The program will generate a random number between [0, n)."
		 << endl << "Enter the value of n: ";

	int n;
	cin >> n;

	cout << endl << "Selected random number = " << nrand(n) << endl;
	return 0;
}