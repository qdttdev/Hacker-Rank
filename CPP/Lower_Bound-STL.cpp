#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> nV;
    int n = 0;
    int q = 0;
    int e = 0;
    
    vector<int>::iterator low; 

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> e;
        nV.push_back(e);
    }

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> e;

        low = lower_bound(nV.begin(), nV.end(), e); 

        // if the value @low_bound == element
        if(nV[low - nV.begin()] == e) 
        {
            cout << "Yes " << (low - nV.begin()) + 1 << endl;
        }
        else
        {
            cout << "No " << (low - nV.begin()) + 1 << endl;
        }
    }    

    return 0;
}

// Iterators:       [1][2][3][4][5][6][7][8]
// Index base-1:     1  1  2  2  6  9  9 15

// p   = find(nV.begin(), nV.end(), e);            
// low = lower_bound (nV.begin(), nV.end(), e); 
// up  = upper_bound (nV.begin(), nV.end(), e);

// p:   returns iterator of position found          --> *p   = value @p
// low: returns iterator of lower bound (inclusive) --> *low = value @low
// up:  returns iterator of upper bound (exclusive) --> *up  = value @up