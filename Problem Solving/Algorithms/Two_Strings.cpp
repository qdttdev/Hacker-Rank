#include <bits/stdc++.h>

using namespace std;

// APPROACH: We want to find if the two strings share a substrings, a substring
// can contain only 1 character and we'll return YES and NO accordingly.
// We will find each character of the smaller string within the bigger string.
// If there exists a character of a smaller string within a bigger string,
// we will return YES, else we will return NO.

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) 
{
    string bigger, smaller;
    string result  = "NO";
    
    if(s1.length() > s2.length())
    {
        bigger = s1;
        smaller = s2;
    }
    else 
    {
        bigger = s2;
        smaller = s1;
    }
    
    for(int i = 0; i < smaller.length(); i++)
    {
        if(bigger.find(smaller[i]) != string::npos)
        {
            result = "YES";
        }      
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
