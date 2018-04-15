#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<string, vector<int>> map;

    vector<int> v = {1, 2, 3};
    map["one"] = v;

    map["two"] = {4, 5, 6};

    for(const auto &kv: map) 
    {
        cout << "Key: " << kv.first << endl;
        for(auto v: kv.second)
            cout << "Value: " << v << endl;
    }

    return 0;
}
