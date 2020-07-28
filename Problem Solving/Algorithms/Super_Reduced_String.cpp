#include <bits/stdc++.h>

using namespace std;

// PROBLEM: Cannot handle case "baab" where "bb" is not handled
// TEST CASES FAILED: 11, 13, 14, 15

// Complete the superReducedString function below.
string superReducedString(string s) 
{
    string r = "";

    for(int i = 0; i < s.length() - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            s[i] = '_';
            s[i+1] = '_';
        }
    }

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != '_')
        {
            r += s[i];
        }

        cout << "NEW STRING: " << r << endl;
    }

    if(r[0] == r[1])
    {
        r = "Empty String";
    } 

    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
