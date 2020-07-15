#include <bits/stdc++.h>

using namespace std;

//      0123
//    0 1112
//    1 1X12
//    2 18X2
//    3 1234
//                             (EDGES)
// -->  if a[i][j] > a[i-1][j]  TOP
//      if a[i][j] > a[i][j-1]  LEFT
//      if a[i][j] > a[i][j+1]  RIGHT
//      if a[i][j] > a[i+1][j]  BOTTOM

// Since we're only checking elements that have 4 edges,
// the elements cannot be borderlines, thus
// we are checking from index 1 instead of 0
// till index end-1 instead of end index.

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) 
{
    for(int i = 1; i < grid.size() - 1; i++)
    {
        for(int j = 1; j < grid.size() - 1; j++)
        {
            if(grid[i][j] > grid[i-1][j] && grid[i][j] > grid[i+1][j]
            && grid[i][j] > grid[i][j-1] && grid[i][j] > grid[i][j+1])
            {
                grid[i][j] = 'X';
            }
        }
    }

    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

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
