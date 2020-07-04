#include <bits/stdc++.h>

using namespace std;

// SOSSPSSQSSOR = 3

// Complete the marsExploration function below.
int marsExploration(string s) 
{
    int diff = 0;

    for(int i = 0; i < s.size(); i=i+3)
    {        
        if(s[i] != 'S')
        {
            diff++;
        }
        
        if(s[i+1] != 'O')
        {
            diff++;
        }
        
        if(s[i+2] != 'S')
        {
            diff++;
        }
    }    

    return diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
