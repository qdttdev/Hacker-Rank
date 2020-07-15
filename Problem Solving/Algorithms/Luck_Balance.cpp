#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// 6 3
// 5 1
// 2 1
// 1 1
// 8 1
// 10 0
// 5 0

// n = 6 --> There are 6 contests, 4 important, 2 not
// k = 3 --> She can lose at most 3 important contests

// She would want to lose k=3 important contests with highest luck:
// (5,1) (2,1) (8,1)
// L = L + (5 + 2 + 8) = -1 + 15 = 14

// She have to win the rest of the important contests

// She would want to lose all unimportant contests:
// (10,0) (5,0)
// L = L + 10 + 5 = 14 + 15 = 29

// Sort the 2D vector on basis of a particular column (col = 0) 
bool sortcol(const vector<int>& v1, 
             const vector<int>& v2) 
{ 
    return v1[0] < v2[0]; 
}

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> c) 
{
    int luck = 0;
    int count = 0;

    sort(c.begin(), c.end(), sortcol); // sort by column[0]: from smallest to largest (ascending)
    reverse(c.begin(), c.end()); // reverse into: from largest to smallest (descending)

    for(int i = 0; i < c.size(); i++)
    {
        if(c[i][1] == 1) // IMPORTANT CONTESTS
        {
            if(count < k) // lose up to k IMPORTANT contests with highest luck
            {
                luck += c[i][0];
                count++;
            }
            else // win the rest
            {
                luck -= c[i][0];
            }
        }

        if(c[i][1] == 0) // lose all UNIMPORTANT CONTESTS
        {
            luck += c[i][0];
        }        
    }

    return luck;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
