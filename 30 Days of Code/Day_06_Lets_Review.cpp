#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int cases = 0;
    cin >> cases;
    cin.ignore(numeric_limits <streamsize>::max(), '\n');

    for(int i = 0; i < cases; i++)
    {
        string s = "";
        string sOdd = "";
        string sEven = "";

        getline(cin, s);

        for(int i = 0; i < s.length(); i++)
        {
            if(i % 2 != 0) // odd
            {
                sOdd += s[i];
            }
            else // even
            {
                sEven += s[i];
            }
        }

        cout << sEven << " " << sOdd << endl;
    }
        
    return 0;
}
