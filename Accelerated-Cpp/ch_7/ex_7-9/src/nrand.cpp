#include <cstdlib>
#include <cmath>
#include <stdexcept>
#include <iostream>

using std::rand;
using std::domain_error;
using std::cout;
using std::endl;

#define MY_RAND_MAX 10

// return a random integer in the range [0, n)
int nrand(int n)
{
	if (n <= 0)
		throw domain_error("Argument to nrand is out of range");
	
	int r;
	if (n <= MY_RAND_MAX) {
		const int bucket_size = MY_RAND_MAX / n;
		do r = rand() / bucket_size;
		while (r >= n);		
	} else {
		do {
			// each int within [0, MY_RAND_MAX) will correspond to one of
			// these buckets:
			// [0->MY_RAND_MAX, MY_RAND_MAX->(2*MY_RAND_MAX), ..., 
			// (MY_RAND_MAX*(n / MY_RAND_MAX))->(MY_RAND_MAX*ceil(n / MY_RAND_MAX))]
			// first, we'll choose one of these buckets
			const int num_buckets = ceil(n / MY_RAND_MAX);
			const int selected_bucket = nrand(num_buckets);
			const int bucket_range_start = selected_bucket * MY_RAND_MAX;
			// now, we'll choose the remaining value to be added 
			// to the starting value of the selected bucket's range
			// this remainder will be chosen randomly from [0, MY_RAND_MAX)
			const int remainder = nrand(MY_RAND_MAX);
			r = bucket_range_start + remainder;
		} while (r >= n);
	}
	
	return r;
}