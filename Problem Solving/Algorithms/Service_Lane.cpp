#include <bits/stdc++.h>

using namespace std;

// OBJECTIVE: Find min width within bound [a,b]

int main()
{
    int n = 0;      // number of width measurements
    int t = 0;      // number of test cases
    int elem = 0;   // element to populate widthList
    vector<int> widthList;    

    cin >> n >> t;

    for(int i = 0; i < n; i++)
    {
        cin >> elem;
        widthList.push_back(elem);
    }

    for(int i = 0; i < t; i++)
    {
        int a = 0;          // beginIndex
        int b = 0;          // endIndex
        int minWidth = 4;   // min width sets to greater than upper bound (1 <= w <= 3)

        cin >> a >> b;

        for(int j = a; j <= b; j++)
        {
            if(widthList[j] < minWidth)
            {
                minWidth = widthList[j];
            }            
        }

        cout << minWidth << endl;
    }

    return 0;
}
