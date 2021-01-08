#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k)
{
    string r = "No";
    string bigger;
    int app = 0;
    int del = 0;
    int operations = 0;
    int common = 0;

    // If string 's' and 't' are the same
    if(s == t)
    {
        // If the number of operations is even (enough for append and delete)
        if(k%2 == 0)
        {
            return "Yes";
        }
        else // Delete s completely and append to t (do not empty the string)
        {
            del = s.length();
            app = s.length();
        }
    }
    else // Else, find the common characters in the two strings
    {
        if(s.length() > t.length())
        {
            bigger = s;
        }
        else
        {
            bigger = t;
        }

        for(int i = 0; i < bigger.length(); i++)
        {
            // If a difference is found, we start deleting from that character
            // to the rest of 's' string (del), then add the rest of 't' string (app)
            if(s[i] != t[i])
            {
                del = s.length() - common;
                app = t.length() - common;
                break;
            }
            else
            {
                common++;
            }
        }
    }

    operations = del + app;

    // If del >= app, meaning we can completely empty the string
    // +1 for empty operation if (k-operations)%2 is odd
    if(del >= app && (k-operations)%2 != 0)
    {
        operations++;
    }

    // If the number of operations is exactly k, or the number of
    // leftover operations is even (enough for del and app = stay same),
    // then print "Yes"
    if(k == operations || ((k-operations)%2 == 0 && k > operations))
    {
        r = "Yes";
    }

    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
