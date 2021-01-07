#include <bits/stdc++.h>

using namespace std;

// APPROACH: Use a for loop to traverse through the given string to calculate the values
// of the subsets of the string, use duplicates to keep track of the number of 
// duplicates of characters. Use another for loop to calculate values of the duplicates
// from 1 to n duplicates and store them in 'r' vector. Finally, traverse through
// 'queries', use sid::find to see if the element in 'r' is found in 'queries'.

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) 
{
    vector<string> r;
    vector<int> values;
    vector<int>::iterator it;
    const int ASCII = 96;
    int sum = 0;
    int duplicates = 1;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == s[i+1])
        {
            duplicates++;
        }
        else 
        {            
            for(int j = 1; j <= duplicates; j++)
            {
                values.push_back(j*(s[i] - ASCII));
            }
            
            duplicates = 1;    
        }        
    }
    
    for(int i = 0; i < queries.size(); i++)
    {
        it = find (values.begin(), values.end(), queries.at(i)); 
        if (it != values.end()) 
        { 
            r.push_back("Yes");
        } 
        else
        {
            r.push_back("No");
        }            
    }
    
    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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
