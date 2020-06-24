#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int,int> b;
    auto it = b.end();
    int n = 0;
    int max = 0;
    int id = 0;    
    int smallestId = 6;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> id;
        it = b.find(id);

        if(it == b.end()) // Start count = 1 if new bird type
        {
            b[id] = 1;
        }
        else // Else increment bird count
        {
            b[id]++;
        }
        
        if(b[id] > max) // If bird count > max count 
        {
            max = b[id];      // updates max
            smallestId = id;  // updates bird id
        }
        else if(b[id] == max && id < smallestId) // if bird count == max count && id < smallestId
        {
            smallestId = id;    // updates smallestId
        }
    }
    
    cout << smallestId << endl;

    return 0;
}
