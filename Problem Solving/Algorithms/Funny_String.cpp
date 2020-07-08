#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) 
{
    int sAbs = 0;
    int rAbs = 0;
    string funny = "Funny";
    string r = s;    
    reverse(r.begin(), r.end());

    for(int i = 0; i < s.size()-1; i++)
    {
        sAbs = abs(s[i] - s[i+1]);
        rAbs = abs(r[i] - r[i+1]);

        if(sAbs != rAbs)
        {
            funny = "Not Funny";
        }
    }

    return funny;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
