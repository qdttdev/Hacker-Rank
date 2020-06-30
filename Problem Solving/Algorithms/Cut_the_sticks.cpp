#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// 6
// 5 4 4 2 2 8 --> min = 2  --> remainder = 6
// 3 2 2 0 0 6 --> min = 2  --> remainder = 4
// 1 0 0 0 0 4 --> min = 1  --> remainder = 2
// 0 0 0 0 0 3              --> remainder = 1

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> a) 
{
    vector<int> sticksToCut;
    int min = 1000;
    int remain = a.size();
    
    sticksToCut.push_back(remain);

    while(remain > 1)
    {
        min = 1000;
        remain = 0;
        
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] < min && a[i] > 0)
            {
                min = a[i];
            }
        }

        for(int i = 0; i < a.size(); i++) 
        {
            a[i] = a[i] - min;
            
            if(a[i] > 0)
            {
                remain++;
            }
        }
        
        if(remain != 0)
        {
            sticksToCut.push_back(remain);
        }
    }

    return sticksToCut;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = cutTheSticks(arr);

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
