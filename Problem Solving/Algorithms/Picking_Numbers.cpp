#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) 
{
    // Objective: We sort the array so that when comparing with base value, it satisfies the condition: diff <= 1
    // It is ensured that the value to compare to the base value is greater than or equal to base value
    // If the condition fails, start on the next base value
    // By "count"-ing the number of values that satisfies "diff <= 1", we can find the "max" value exists, which is the size of the subarray
    
    int max = 0;
    int count = 0;
    sort(a.begin(), a.end());

    for(int i = 0; i < a.size(); i++) // going through every element as base value
    {
        count = 1; // the base value is the first element in the subarray

        for(int j = i+1; j < a.size(); j++) // comparing these elements to base value
        {
            if(abs(a[i]-a[j]) <= 1)
            {
                count++;
                if(count > max)
                {
                    max = count;
                }
            }
            else // if condition doesn't meet, move on to the next base value
            {
                break;
            }
        }
    }

    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
