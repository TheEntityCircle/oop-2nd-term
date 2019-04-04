#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<string> c;
    c.insert("apple");
    c.insert("banana");
    c.insert("cucumber");
    c.insert("orange");
    c.insert("o");
    c.insert("pineapple");

    // Я просто хотел не включать значение самого upper_bound
    set<string> selection;
    copy(c.lower_bound("b"), c.upper_bound("o") - 1, inserter(selection, selection.end()));

    for(set<string>::iterator it = selection.begin(); it != selection.end(); it++)
    {
        cout << *it << endl;
    }

    return 0; 
}
