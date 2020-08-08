#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) 
{
    string t = "hackerrank";    // Standard string to be compared to
    int j = 0;                  // Index of string "t"

    if(s.length() < t.length())
    {
        return "NO";
    }
    else 
    {
        // Traverse through test string while comparing to standard string
        for(int i = 0; i < s.length(); i++) 
        {
            if(s[i] == t[j] && j <= t.length()) // If character matches
            {
                j++; // Increment index of string "t" iff there's a match
            }
        }

        if(j == t.length())
        {
            return "YES";
        }
        else // If test string "s" doesn't have all elements of string "t"
        {
            return "NO";
        }
    }
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

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
