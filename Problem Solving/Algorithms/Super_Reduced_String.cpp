#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) 
{    
    int i = 0;
    
    // Loops through all elements of the string
    while(i < s.length())
    {
        // If two adjacent elements are the same, erase them
        if(s[i] == s[i+1])
        {
            s.erase(s.begin()+i);
            s.erase(s.begin()+i);
            
            // reset index because we have a new (erased) string (account for case "baab")
            i = 0;
        }
        else  // Else, increment to check the next element
        {
            i++;
        }
    }
    
    if(s == "")
    {
        s = "Empty String";
    }
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
