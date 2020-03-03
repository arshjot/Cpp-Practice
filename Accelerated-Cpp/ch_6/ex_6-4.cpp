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

    // we can also use inserter or front_inserter 
    // instead of back_inserter
    copy(u.begin(), u.end(), back_inserter(v));

    for (vector<int>::const_iterator iter = u.begin();
         iter != u.end(); ++iter)
    {
        cout << (*iter) << endl;
    }
    cout << endl;

    for (vector<int>::const_iterator iter = v.begin();
         iter != v.end(); ++iter)
    {
        cout << (*iter) << endl;
    }
 
    return 0;
}
