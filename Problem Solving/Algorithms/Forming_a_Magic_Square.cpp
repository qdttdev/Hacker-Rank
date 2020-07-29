#include <bits/stdc++.h>

using namespace std;

// 5 3 4            8 3 4
// 1 5 8    -->     1 5 9
// 6 4 2            6 7 2

// 5 + 3 + 4 = 12
// 1 + 5 + 8 = 14
// 6 + 4 + 2 = 12

// 5 + 1 + 6 = 12
// 3 + 5 + 4 = 12
// 4 + 8 + 2 = 14

// 5 + 5 + 2 = 12
// 6 + 5 + 4 = 15 ***

// 4 9 2            4 8 2
// 3 5 7    -->     4 5 7
// 8 1 5            6 1 6

// 4 + 9 + 2 = 15
// 3 + 5 + 7 = 15
// 8 + 1 + 5 = 14

// 4 + 3 + 8 = 15
// 9 + 5 + 1 = 15
// 2 + 7 + 5 = 14

// 4 + 5 + 5 = 14 ***
// 2 + 5 + 8 = 15 


// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
