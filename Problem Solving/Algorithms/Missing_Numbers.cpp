// Find an element in a vector:
// https://www.geeksforgeeks.org/std-find-in-cpp/

// Remove duplicates in a vector:
// https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// APPROACH: There are two vectors of integer, we will traverse through
// the shorter vector, then find and remove the element of 'a' that is found in 'b'.
// Whichever element that is left in 'b' is the missing numbers. The return
// of the missing number must be in ascending order and does not contain duplicates.

// Complete the missingNumbers function below.
vector<int> missingNumbers(vector<int> a, vector<int> b) 
{
    vector<int>::iterator it;
    
    // Sort, find and remove the found element of 'a' in 'b' from 'b' vector
    for(int i = 0; i < a.size(); i++)
    {
        it = find(b.begin(), b.end(), a.at(i));
        
        if(it != b.end())
        {
            b.erase(b.begin() + (it - b.begin()));
        }
    }

    // Sort and remove duplicates
    sort(b.begin(), b.end());
    b.erase( unique( b.begin(), b.end() ), b.end() );

    return b;
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

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split_string(brr_temp_temp);

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    vector<int> result = missingNumbers(arr, brr);

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
