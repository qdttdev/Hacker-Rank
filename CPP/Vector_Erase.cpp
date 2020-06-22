#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
   vector<int> v;
    int n = 0;
    int x = 0;
    int a = 0;
    int b = 0;
    int e = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> e;
        v.push_back(e);
    }

    cin >> x >> a >> b;

    v.erase(v.begin()+x-1);                 // erase the xth element
    v.erase(v.begin()+a-1,v.begin()+b-1);   // erase[a,b)

    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
