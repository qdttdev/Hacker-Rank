#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) 
{
    int common = 0;    

    for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
        {
            if(s1[i] == s2[j])
            {
                common++;
                s1[i] = '_';
                s2[j] = '_';
                break; // if match found, proceed to next character
            }
        }
    }

    return (s1.size() - common) + (s2.size() - common);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
