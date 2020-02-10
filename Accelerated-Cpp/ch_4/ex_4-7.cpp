#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<double> num_list;
	double x;
	// invariant: int_list contains all the integers read so far
	while (cin >> x)
	    num_list.push_back(x);

	cout << "Average of numbers = " 
		 << accumulate(num_list.begin(), num_list.end(), 0.0) / num_list.size()
		 << endl;
	
	return 0;
}
