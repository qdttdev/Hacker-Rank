#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//  BUDGET      COST        WRAPPER_BAR 
//  10          2           5           --> 10/2 = 5 chocolates = 5 wraps - 5
//                                               = 1 chocolate  = 1 wrap
//                                             === 6 CHOCOLATES

//  12          4           4           --> 12/4 = 3 chocolates = 3 wraps               
//                                             === 3 CHOCOLATES

//  6           2           2           --> 6/2  = 3 chocolates = 3 wraps - 2 
//                                               = 1 chocolate  = 1 wraps + 1
//                                               = 1 chocolate  = 0 wrap
//                                             === 5 CHOCOLATES

// Complete the chocolateFeast function below.
int chocolateFeast(int budget, int cost, int wrapperBar) 
{
    int choco = 0;
    int wrapper = 0;

    choco = budget/cost;
    wrapper = choco;

    while(wrapper >= wrapperBar)
    {
        wrapper = wrapper - wrapperBar;
        choco++;
        wrapper++;
    }

    return choco;    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string ncm_temp;
        getline(cin, ncm_temp);

        vector<string> ncm = split_string(ncm_temp);

        int n = stoi(ncm[0]);

        int c = stoi(ncm[1]);

        int m = stoi(ncm[2]);

        int result = chocolateFeast(n, c, m);

        fout << result << "\n";
    }

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
