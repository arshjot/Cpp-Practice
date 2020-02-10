#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int max_i = 1000; // change this value for upper limit
	int max_len_i = to_string(max_i).length();
	int max_len_i_i = to_string(max_i*max_i).length();

	for (int i=1; i<=max_i; ++i){
		cout << setw(max_len_i) << i 
			 << setw(max_len_i_i + 1) << i*i << endl; 
	}
	
	return 0;
}
