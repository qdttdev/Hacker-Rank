#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    vector<int> v;
    int n = 0;
    int e = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> e;
        v.push_back(e);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
