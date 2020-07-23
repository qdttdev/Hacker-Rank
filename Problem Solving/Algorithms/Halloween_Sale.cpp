#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the howManyGames function below.
int howManyGames(int p, // price 
                 int d, // discount
                 int m, // minimum
                 int s) // spend amount available
{
    int game = 0;
    int cost = 0;
    int nextPrice = 0;

    // First game:  cost      = first price
    //              nextPrice = first price as base reference
    cost = p;
    nextPrice = p;

    if(cost > s)
    {
        return 0;
    }
    else 
    {
        while(cost <= s)
        {
            game++;
            
            nextPrice -= d;

            if(nextPrice < m)
            {
                nextPrice = m;
            }
            
            cost += nextPrice;
        }
    }

    return game;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string pdms_temp;
    getline(cin, pdms_temp);

    vector<string> pdms = split_string(pdms_temp);

    int p = stoi(pdms[0]);

    int d = stoi(pdms[1]);

    int m = stoi(pdms[2]);

    int s = stoi(pdms[3]);

    int answer = howManyGames(p, d, m, s);

    fout << answer << "\n";

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
