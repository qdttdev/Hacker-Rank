#include <bits/stdc++.h>

using namespace std;

int main()
{
    list<int> a;
    int n = 0;
    int d = 0;
    int t = 0;

    cin >> n >> d;

    // Populate the list
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }

    // Rotate the list
    for(int i = 0; i < d; i++)
    {
        t = a.front();
        a.pop_front();
        a.push_back(t);
    }

    // Display the list
    for(auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    
    return 0;
}