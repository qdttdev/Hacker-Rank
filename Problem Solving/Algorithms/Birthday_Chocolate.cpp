#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//                                  m = 1; c = 5 = size+1-m = 5+1-1 = 5
// s = 5 = {1, 2, 1, 3, 2}          m = 2; c = 4 
// d = 3                            m = 3; c = 3 
// m = 2                            m = 4; c = 2
//                                  m = 5; c = 1

// d = sum value of contiguous segment
// m = length

// Complete the birthday function below.
int birthday(vector<int> s, int d, int m) 
{
    int way, sum, length;
    way = 0;

    // Number of comparisons can occur denoted by j
    for(int j = 0; j < s.size() + 1 - m; j++)
    {
        sum = 0;
        length = 0;
        
        // Number of times accumulated denoted by k
        for(int k = 0, i = j; k < m; k++, i++)
        {
            sum += s[i];
            length++;

            if(sum == d && length == m)
            {
                way++;
            }            
        }           
    }

    return way;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    string dm_temp;
    getline(cin, dm_temp);

    vector<string> dm = split(rtrim(dm_temp));

    int d = stoi(dm[0]);

    int m = stoi(dm[1]);

    int result = birthday(s, d, m);

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
