#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// 20 3 6 80

// 20               C = 1
// 20-3 = 17        C = 2
// 17-3 = 14        C = 3
// 14-3 = 11        C = 4
// 11-3 = 8         C = 5
// 8-3  = 5 --> 6   C = 6
// SUM = $76 < 80

// 1 100 1 9777 = 9777
// 88 77 88 9912 = 112
// 73 72 44 9163 = 207
// 95 68 66 2249 = 33

// Complete the howManyGames function below.
int howManyGames(int initPrice, int discount, int minPrice, int spending) 
{
    int sum = 0;
    int games = 0;
    int nextCost = initPrice - discount;
    
    sum = initPrice;
    
    if(sum > spending)
    {
        return 0;
    }
    else
    {
        
        if(discount > initPrice)
        {
            cout << spending;
            return spending;
        }
        
        games++;
        sum += nextCost;
    }
    
    while(sum <= spending)
    {
        nextCost -= discount;
        
        if(nextCost < minPrice)
        {
            nextCost = minPrice;
        }
        
        sum += nextCost;
        games++;
        
        cout << "S: " << sum << "\tG:" << games << endl;
    }
    
    return games;
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
