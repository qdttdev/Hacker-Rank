#include <bits/stdc++.h>

using namespace std;

// n = 4, a = 10, b = 100 
// 0, 10, 20, 30        0, +a, +a, +a 
// 0, 10, 20, 120       0, +a, +a, +b
// 0, 10, 110, 120      0, +a, +b, +a
// 0, 10, 110, 210      0, +a, +b, +b
// 0, 100, 110, 120     0, +b, +a, +a
// 0, 100, 110, 210     0, +b, +a, +b
// 0, 100, 200, 210     0, +b, +b, +a
// 0, 100, 200, 300     0, +b, +b, +b

// Solutions: 3a, 2a+b, 2b+a, 3b = 30, 120, 210, 300
// (n-1)a+0b, (n-2)a+1b, (n-3)a+2b, (n-4)a+3b

// Refer to this for most efficient ways to remove duplicates in a vector: 
// https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector

// Complete the stones function below.
vector<int> stones( int n, // the number of non-zero stones found 
                    int a, // one possible difference
                    int b) // other possible difference
{
    vector<int> v;
    int r = 0;
    
    for(int i = 0, j = 1; i < n; i++, j++)
    {
        r = (n-j)*a + i*b;
        v.push_back(r);
    }

    // Remove duplicates using vector, sort, and unique
    sort(v.begin(), v.end());
    v.erase(  unique(v.begin(),v.end()), v.end()  );

    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
