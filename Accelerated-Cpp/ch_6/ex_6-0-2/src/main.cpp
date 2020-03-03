#include <iostream>
#include <vector>
#include <string>
#include "palindrome.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
 
int main()
{
    string s;
    vector<string> palindromes;
 
    while (cin >> s) {
        if (is_palindrome(s))
            palindromes.push_back(s);
    }
 
    // print lowercase words followed by uppercase ones
    if (palindromes.size() != 0) {
        cout << endl << "Palindromes found in the input dictionary: " << endl;
        for (vector<string>::const_iterator iter = palindromes.begin();
             iter != palindromes.end(); ++iter)
            cout << (*iter) << endl;

        cout << endl << "Longest palindrome: " << endl;
        cout << longest_string(palindromes) << endl;
    }
    else
        cout << endl << "No palindromes found in the input dictionary" << endl;
 
    return 0;
}
