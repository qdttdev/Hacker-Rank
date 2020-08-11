#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) 
    {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) 
        {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int s = 0;
    int max = -999; // Since -9 <= arr[i][j] <= 9

    for(int i = 0; i < arr.size()-2; i++) // rows
    {
        for(int j = 0; j < arr.size()-2; j++) // columns
        {
            s = arr[i][j]   + arr[i][j+1]   + arr[i][j+2]
                            + arr[i+1][j+1] +
                arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

            if(s > max)
            {
                max = s;
            }
        }        
    }
    
    cout << max;

    return 0;
}
