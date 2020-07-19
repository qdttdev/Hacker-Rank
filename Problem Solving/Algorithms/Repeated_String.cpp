#include <bits/stdc++.h>

using namespace std;

// Example: aba, 10 = aba aba aba a --> 7 'a'

// First, we find the number of letter 'a' in the original repeated string --> 2
// Second, we find how many times the string will be repeated (non-floating point) --> 10 / stringSize = 10/3 = 3 
// --> Total of letter 'a' so far: letterA = 2 * 3 = 6
// Third, we find the remainder of letters to repeat in string --> 10 % stringSize = 1 
// --> Repeats one more letter in the string, the first letter happens to be 'a' -->  letterA = 6 + 1 = 7

// Complete the repeatedString function below.
long repeatedString(string s, long n) 
{
    long letterA = 0;
    long repeat = 0;
    long remainder = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a')
        {
            letterA++;
        }
    }

    remainder = n % s.size();
    repeat = n / s.size();
    letterA = letterA * repeat;

    for(int i = 0; i < remainder; i++)
    {
        if(s[i] == 'a')
        {
            letterA++;
        }
    }

    return letterA;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
