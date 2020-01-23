#include <iostream>

// say what standard-library names we use
using std::cin;
using std::cout;
using std::endl;

int main()
{
	// ask for the numbers to be compared
	cout << "Please enter the first number for the comparison: ";
	int firstNum;
	cin >> firstNum;

	cout << "Please enter the second number for the comparison: ";
	int secondNum;
	cin >> secondNum;

	if (firstNum > secondNum)
		cout << "First number is greater than the second number";
	else {
		if (secondNum > firstNum)
			cout << "Second number is greater than the first number";
		else
			cout << "Both numbers are equal";
	}
	cout << endl;

	return 0;
}
