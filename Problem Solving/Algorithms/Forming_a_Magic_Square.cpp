#include <bits/stdc++.h>

using namespace std;

/****************************************************************************************

    EXAMPLE 
    5 3 4            8 3 4
    1 5 8    -->     1 5 9
    6 4 2            6 7 2

    EXAMPLE 0
    4 9 2            4 9 2
    3 5 7    -->     3 5 7
    8 1 5            8 1 6

    EXAMPLE 1
    4 8 2            4 9 2
    4 5 7    -->     3 5 7
    6 1 6            8 1 6

    PROBLEM RECOGNITION:     
    - The magic sum is 15.
    - The center of the 3x3 matrix is 5. 
    
    --> With 5 as the center, we have summing pairs on opposite sides,
    their summation equals 10 (15 - 5 = 10). The summing pairs are:

    1 & 9
    2 & 8                                   O X O
    3 & 7           with the 3x3 matrix:    X 5 X
    4 & 6                                   O X O

    5 & 5 is not a pair because all elements [1,9] must exist in the matrix.

    --> Recognize that Corner pairs (O) are 2 & 8 and 6 & 4, 
        making Wedged pairs (X) 1 & 9 and 3 & 7.


    IN SHORT, WE HAVE:          Notice that:
    [00 01 02]                  --> 11 is always 5
    [10 11 12]                  --> 00 & 22, 02 & 20 are pairs 2 & 8 or 6 & 4
    [20 21 22]                  --> 01 & 21, 10 & 12 are pairs 1 & 9 or 3 & 7

    --> Using these characteristic, we can generate 08 arrangements of the 3x3 matrix.    

    ----------------------------------------------------------------
                        08 POSSIBLE ARRANGEMENTS
    ----------------------------------------------------------------

                    2 9 4   2 7 6   4 9 2   6 7 2
                    7 5 3   9 5 1   3 5 7   1 5 9
                    6 1 8   4 3 8   8 1 6   8 3 4

                    8 3 4   8 1 6   4 3 8   6 1 8
                    1 5 9   3 5 7   9 5 1   7 5 3
                    6 7 2   4 9 2   2 7 6   2 9 4  

    OBJECTIVE:  Calculate the cost for all 8 possibilities above and
                result the minimum cost.

****************************************************************************************/

// Helper Function to Calculate Cost for 8 possible Cases
int computeCost(vector<vector<int>> s, vector<vector<int>> m)
{
    int cost = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cost += abs(s[i][j] - m[i][j]);
        }
    }

    return cost;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) 
{
    vector<int> costAr;

    const vector<vector<int>> m1 { {2,9,4}, {7,5,3}, {6,1,8} };
    const vector<vector<int>> m2 { {2,7,6}, {9,5,1}, {4,3,8} };
    const vector<vector<int>> m3 { {4,9,2}, {3,5,7}, {8,1,6} };
    const vector<vector<int>> m4 { {6,7,2}, {1,5,9}, {8,3,4} };
    const vector<vector<int>> m5 { {8,3,4}, {1,5,9}, {6,7,2} };
    const vector<vector<int>> m6 { {8,1,6}, {3,5,7}, {4,9,2} };
    const vector<vector<int>> m7 { {4,3,8}, {9,5,1}, {2,7,6} };
    const vector<vector<int>> m8 { {6,1,8}, {7,5,3}, {2,9,4} };    

    costAr.push_back(computeCost(s,m1));
    costAr.push_back(computeCost(s,m2));
    costAr.push_back(computeCost(s,m3));
    costAr.push_back(computeCost(s,m4));
    costAr.push_back(computeCost(s,m5));
    costAr.push_back(computeCost(s,m6));
    costAr.push_back(computeCost(s,m7));
    costAr.push_back(computeCost(s,m8));

    sort(costAr.begin(),costAr.end());

    return costAr[0];
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
