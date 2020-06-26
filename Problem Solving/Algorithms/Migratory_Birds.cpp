#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> a) 
{
    int maxCount = 0;
    int minId = 6;
    vector<int> bCount(6,0);

    for(int i = 0; i < a.size(); i++)
    {
        switch (a[i]) // Since the types are guaranteed to be 1-5
        {
            case 1: bCount[1]++;
                    break;
            case 2: bCount[2]++;
                    break;
            case 3: bCount[3]++;
                    break;
            case 4: bCount[4]++;
                    break;
            case 5: bCount[5]++;
                    break;
        }
    }

    for(int i = 1; i < 6; i++)
    {
        if(maxCount < bCount[i])
        {
            maxCount = bCount[i];
            minId = i;
        }
    }

    return minId;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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

// THIS MAP APPROACH WITHOUT ADDITIONAL GIVEN FUNCTIONS

// int main()
// {
//     map<int,int> b;
//     auto it = b.end();
//     int n = 0;
//     int max = 0;
//     int id = 0;    
//     int smallestId = 6;

//     cin >> n;

//     for(int i = 0; i < n; i++)
//     {
//         cin >> id;
//         it = b.find(id);

//         if(it == b.end()) // Start count = 1 if new bird type
//         {
//             b[id] = 1;
//         }
//         else // Else increment bird count
//         {
//             b[id]++;
//         }
        
//         if(b[id] > max) // If bird count > max count 
//         {
//             max = b[id];      // updates max
//             smallestId = id;  // updates bird id
//         }
//         else if(b[id] == max && id < smallestId) // if bird count == max count && id < smallestId
//         {
//             smallestId = id;    // updates smallestId
//         }
//     }
    
//     cout << smallestId << endl;

//     return 0;
// }
