#include <bits/stdc++.h>

using namespace std;

// PROBLEM: Cannot handle case "baab" where "bb" is not handled

// Complete the superReducedString function below.
string superReducedString(string s) 
{


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
