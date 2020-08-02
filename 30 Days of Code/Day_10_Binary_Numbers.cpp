#include <bits/stdc++.h>

using namespace std;

// 5 % 2 = 2    R1  ^
// 2 % 2 = 1    R0  ^
// 1 % 2 = 0    R1  ^   Reads from Bottom to Top

int main()
{
    string s = "";
    int n = 0;
    int count = 1;
    int max = 1;

    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while(n >= 1)
    {
        if(n % 2 == 0)
        {
            s += '0';
        }
        else 
        {
            s += '1';
        }

        n = n / 2;
    }

    reverse(s.begin(),s.end());

    for(int i = 0; i < s.size()-1; i++)
    {
        if(s[i] == s[i+1] && s[i] == '1')
        {
            count++;
            if(count > max)
            {
               max = count; 
            }            
        }
        else
        {
            count = 1;
        }
    }

    cout << max;

    return 0;
}
