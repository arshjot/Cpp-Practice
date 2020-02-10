#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double max_i = 1000; // change this value for upper limit
	double max_len_i = log10(max_i) + 1;
	double max_len_i_i = log10(max_i*max_i) + 1;

	for (double i=1; i<=max_i; ++i){
		cout << setw(max_len_i) << i 
			 << setw(max_len_i_i + 1) << i*i << endl; 
	}
	
	return 0;
}
