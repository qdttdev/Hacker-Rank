#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// FAILING TEST CASES 6, 7, 8, 9 FOR EXCEEDED TIME LIMIT --> NEEDS OPTIMIZATION

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) 
{
    vector<int> aRank;
    int rankVal;
    int rankOrder;

    for(int i = 0; i < alice.size(); i++)
    {
        vector<int> scoresDup(scores);
        rankOrder = 1;

        scoresDup.push_back(alice[i]);
        sort(scoresDup.begin(),scoresDup.end(),greater<int>());

        // for(int i = 0; i < scoresDup.size(); i++)
        // {
        //     cout << scoresDup[i] << " ";
        // }

        rankVal = scoresDup[0];  

        for(int j = 0; j < scoresDup.size()-1; j++)
        {
            // cout << "\nalice[i]  = " << alice[i] << endl;
            // cout << "rankVal   = " << rankVal << endl;
            // cout << "rankOrder = " << rankOrder << endl << endl;

            if(alice[i] < rankVal)
            {
                rankVal = scoresDup[j+1];
                if(scoresDup[j] > scoresDup[j+1])
                {
                    rankOrder++;
                }                
            }
            else
            {                
                break;
            }
        } 

        aRank.push_back(rankOrder);   
        cout << "PUSHING: " << rankOrder << endl;  
    }

    return aRank;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

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
