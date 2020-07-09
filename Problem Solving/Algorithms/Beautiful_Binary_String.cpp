// 010 1 010
// 011 1 010    (1)
// 011 1 011    (2)

// 010 010 1 010
// 011 010 1 010    (1)
// 011 011 1 010    (2)
// 011 011 1 011    (3)

// GOAL: Not having "010" by changing it into "011"

#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string s) 
{
    int changes = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0' && s[i+1] == '1' && s[i+2] == '0')
        {
            s[i+2] = '1';
            changes++;
        }
    }
    
    return changes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
