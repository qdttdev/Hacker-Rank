#include <bits/stdc++.h>

using namespace std;

//  1 1 1 0 0 0     0 1 1 1 0 0     0 0 1 1 1 0     0 0 0 1 1 1
//  0 1 0 0 0 0     0 0 1 0 0 0     0 0 0 1 0 0     0 0 0 0 1 0
//  1 1 1 0 0 0     0 1 1 1 0 0     0 0 1 1 1 0     0 0 0 1 1 1
//  0 0 0 0 0 0     0 0 0 0 0 0     0 0 0 0 0 0     0 0 0 0 0 0
//  0 0 0 0 0 0     0 0 0 0 0 0     0 0 0 0 0 0     0 0 0 0 0 0
//  0 0 0 0 0 0     0 0 0 0 0 0     0 0 0 0 0 0     0 0 0 0 0 0

//  0 0 0 0 0 0     
//  1 1 1 0 0 0     
//  0 1 0 0 0 0     
//  1 1 1 0 0 0     
//  0 0 0 0 0 0     
//  0 0 0 0 0 0     

//  0 0 0 0 0 0
//  0 0 0 0 0 0
//  1 1 1 0 0 0
//  0 1 0 0 0 0
//  1 1 1 0 0 0
//  0 0 0 0 0 0

//  0 0 0 0 0 0                                     0 0 0 0 0 0
//  0 0 0 0 0 0                                     0 0 0 0 0 0
//  0 0 0 0 0 0                                     0 0 0 0 0 0
//  1 1 1 0 0 0                                     0 0 0 1 1 1
//  0 1 0 0 0 0                                     0 0 0 0 1 0
//  1 1 1 0 0 0                                     0 0 0 1 1 1

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> a) 
{
    int s = 0;
    int max = -999;

    for(int i = 0; i < a.size()-2; i++)
    {
        for(int j = 0; j < a.size()-2; j++)
        {
            s = a[i][j] + a[i][j+1]   + a[i][j+2]
                        + a[i+1][j+1]
            + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];

            if(s > max)
            {
                max = s;
            }
        }        
    }

    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
