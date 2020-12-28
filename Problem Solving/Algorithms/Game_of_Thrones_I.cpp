#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s)
{
    string result = "YES";
    int odd = 0;

    for(char i = 'a'; i <= 'z'; i++)
    {
        // If there are 'lonely' characters
        if(count(s.begin(),s.end(),i) % 2 != 0)
        {
            // If there is only one count of a character
            if(count(s.begin(),s.end(),i) % 2 == 1)
            {
                odd++;
            }

            result = "NO";
        }

        // If there are more than one odd, can't be palindrome
        if(odd == 1)
        {
            result = "YES";
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
