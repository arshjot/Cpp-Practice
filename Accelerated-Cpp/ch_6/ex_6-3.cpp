// The below program gives a "Segmentation fault" error
// because v is an empty vector so cannot accomodate 
// elements of u
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using std::vector;
using std::cin;
using std::cout;
using std::endl;
 
int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), v.begin());

    for (vector<int>::const_iterator iter = u.begin();
         iter != u.end(); ++iter)
    {
        cout << (*iter) << endl;
    }

    for (vector<int>::const_iterator iter = v.begin();
         iter != v.end(); ++iter)
    {
        cout << (*iter) << endl;
    }
 
    return 0;
}
