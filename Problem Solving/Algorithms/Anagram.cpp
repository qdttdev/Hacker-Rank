#include <bits/stdc++.h>

using namespace std;

// APPROACH: Erase the common character of both strings and the
// leftover, which is the string length of one of the substrings
// are the characters that need to be replaced to achieve an
// anagram. Note that we only have to remove the character from
// ONE of the substrings.

// Complete the anagram function below.
int anagram(string s)
{
    int count = 0;
    string s1, s2;
    bool reset = false;

    // If the string length is an odd number, cannot be anagram
    if(s.length() % 2 != 0)
    {
        count = -1;
    }
    else
    {
        // Split the string into two substrings
        s1 = s.substr(0, s.length()/2);
        s2 = s.substr(s.length()/2, s.length());

        // Traverse through the second string
        for(int i = 0; i < s2.length(); i++)
        {
            // If a character of s1 is found in s2
            if(s1.find(s2[i]) != string::npos)
            {
                // Then we erase the commmon character in s1
                s1.erase(s1.begin() + s1.find(s2[i]));
            }
        }

        // The 'uncommon' characters are replacable for an anagram
        count = s1.length();
    }

    return count;
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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
