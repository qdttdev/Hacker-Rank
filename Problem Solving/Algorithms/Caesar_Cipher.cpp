#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k)
{
    int remainder = 0;

    // To eliminate cycles
    k = k % 26;

    // Go through the string to encrypt each character
    for(int i = 0; i < s.length(); i++)
    {
        // Only encrypt if it is an alphabetical character
        if(isalpha(s[i]))
        {
            // If the new character is still within 'a-z' then proceed
            // NOTE: There's a special case: W + 10 = a,
            // so we have to include islower and isupper
            if((s[i] + k <= 'z' && s[i] + k >= 'a' && islower(s[i]))
            || (s[i] + k <= 'Z' && s[i] + k >= 'A' && isupper(s[i])))
            {
                s[i] = s[i] + k;
            }
            else // Else, find the character by the remainder
            {
                if(islower(s[i]))
                {
                    remainder = k - ('z' - s[i]);
                    s[i] = 'a' + remainder - 1;
                }
                else
                {
                    remainder = k - ('Z' - s[i]);
                    s[i] = 'A' + remainder - 1;
                }
            }
        }
    }

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
