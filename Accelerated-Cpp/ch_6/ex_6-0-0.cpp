// §6.1 Different ways to concatenate a picture
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
 
int main()
{
    string word;

    vector<string> pic_0;
    cout << "Define first collection below:" << endl;
    while (cin >> word)
        pic_0.push_back(word);
    cin.clear();

    vector<string> pic_1;
    cout << "Define second collection below:" << endl;
    while (cin >> word)
        pic_1.push_back(word);
    cin.clear();

    // append using push_back method
    vector<string> push_back_out = pic_0;
    for (vector<string>::const_iterator i = pic_1.begin();
        i != pic_1.end(); ++i)
    push_back_out.push_back(*i);

    // append using insert method
    vector<string> insert_out = pic_0;
    insert_out.insert(insert_out.end(), pic_1.begin(), pic_1.end());

    // append using copy method
    vector<string> copy_out = pic_0;
    copy(pic_1.begin(), pic_1.end(), back_inserter(copy_out));
 
    // print all concatenated outputs
    cout << endl << "Push back method output: " << endl;
    for (vector<string>::const_iterator iter = push_back_out.begin();
         iter != push_back_out.end(); ++iter)
        cout << (*iter) << endl;
    
    cout << endl << "Insert method output: " << endl;
    for (vector<string>::const_iterator iter = insert_out.begin();
         iter != insert_out.end(); ++iter)
        cout << (*iter) << endl;

    cout << endl << "Copy method output: " << endl;
    for (vector<string>::const_iterator iter = copy_out.begin();
         iter != copy_out.end(); ++iter)
        cout << (*iter) << endl;
 
    return 0;
}
