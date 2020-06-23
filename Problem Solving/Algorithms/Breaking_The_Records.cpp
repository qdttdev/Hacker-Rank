#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// 9
// 10 5 20 20 4 5 2 25 1

// GAME    SCORE   MIN     MAX          MIN+    MAX+
// 0        10      10      10
// 1        5       5*                  +1       
// 2        20      5       20*                 +1
// 3        20      5       
// 4        4       4*                  +1
// 5        5                 
// 6        2       2*                  +1
// 7        25              25*                 +1
// 8        1       1*                  +1
//                                      
// RESULT: max, min = 4, 2

// Complete the breakingRecords function below.
vector<int> breakingRecords(vector<int> scores) 
{
    vector<int> recordsBroke;
    int leastPoints = 0;
    int mostPoints = 0;
    int min;
    int max;

    min = scores[0];
    max = scores[0];

    for(int i = 1; i < scores.size(); i++)
    {
        if(min > scores[i])
        {
            min = scores[i];
            leastPoints++;
        }

        if(max < scores[i])
        {
            max = scores[i];
            mostPoints++;
        }
    }

    recordsBroke.push_back(mostPoints);
    recordsBroke.push_back(leastPoints);

    return recordsBroke;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    vector<int> result = breakingRecords(scores);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
