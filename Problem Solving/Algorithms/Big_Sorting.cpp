#include <bits/stdc++.h>

using namespace std;

// Helper function to compare integer for the Sort (Sort ascending < < <)
bool stringCompare(string s1, string s2) 
{
    if(s1.size() == s2.size())          // If they have the same size:
    {
        return s1 < s2;                 // Return their ascii comparison.
    }
    else                                // Ele sizes aren't the same:
    {
        return s1.size() < s2.size();   // Return size comparison.
    }
}

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) 
{
    sort(unsorted.begin(), unsorted.end(), stringCompare);
    return unsorted;    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
