// Compute and print the quartiles

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;        using std::setprecision;
using std::cout;       using std::string;
using std::endl;       using std::streamsize;
using std::sort;       using std::vector;

int main()
{
	// ask for the list of integers
	cout << "Enter all the integers for which "
	        "the quartiles are required, "
	        "followed by end-of-file: ";

	vector<double> int_list;
	double x;
	// invariant: int_list contains all the integers read so far
	while (cin >> x)
	    int_list.push_back(x);
	
	// check that the length of int_list is atleast 4
	typedef vector<double>::size_type vec_sz;
	vec_sz size = int_list.size();
	if (size == 0) {
		cout << endl << "You must enter atleast one value. "
		                "Please try again." << endl;
		return 1;
	}

	// if size is 1, all quartiles will be the same
	if (size == 1) {
		streamsize prec = cout.precision();
		cout << "The quartiles are:" << setprecision(3) << endl
		     << "Q1 : " << int_list[0] << endl
		     << "Q2 : " << int_list[0] << endl
		     << "Q3 : " << int_list[0] << endl
		     << setprecision(prec) << endl;
		return 0;
	}
	
	// sort the list of integers
	sort(int_list.begin(), int_list.end());

	// compute the quartiles
	double q1, q2, q3;

	// compute Q2 (normal median)
	vec_sz mid = size/2;
	q2 = size % 2 == 0 ? (int_list[mid] + int_list[mid-1]) / 2
	                   : int_list[mid];

	// compute Q1 & Q3
	// separate first half (do not include median if total number is odd)
	// and calculate median
	vector<double> first_half, second_half;
    first_half = vector<double>(int_list.begin(), int_list.begin() + mid);
    second_half = size % 2 == 0 ? vector<double>(int_list.begin() + mid, int_list.end())
                                : vector<double>(int_list.begin() + mid + 1, int_list.end());

	size = first_half.size();
	mid = size/2;
	q1 = size % 2 == 0 ? (first_half[mid] + first_half[mid-1]) / 2
	                   : first_half[mid];

	size = second_half.size();
	mid = size/2;
	q3 = size % 2 == 0 ? (second_half[mid] + second_half[mid-1]) / 2
	                   : second_half[mid];

	// print the quartiles
	streamsize prec = cout.precision();
	cout << "The quartiles are:" << setprecision(3) << endl
	     << "Q1 : " << q1 << endl
	     << "Q2 : " << q2 << endl
	     << "Q3 : " << q3 << endl
	     << setprecision(prec) << endl;
	
	return 0;
}
