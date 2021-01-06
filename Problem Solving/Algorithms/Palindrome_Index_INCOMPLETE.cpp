// Fails test cases 5, 6, 7, 10, 12, 13, 14 --> Time exceeds --> Needs optimization

#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s)
{
    string temp;
    string a, b;
    int r = -1;

    for(int i = 0; i < s.length(); i++)
    {
        temp = s;
        temp.erase(temp.begin()+i);
        a = temp;
        b = temp;
        
        reverse(b.begin(), b.end());
        
        if(a == b)
        {
            r = i;
            break;
        }
    }

    return r;
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

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
