// concatenate all elements of a vector<string>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
 
int main()
{
    vector<string> words(10, "hello");

    // note: using accumulate is not efficient for 
    // versions older than C++20
    string concat = accumulate(words.begin(), words.end(), string{});
    cout << concat << endl;

    return 0;
}