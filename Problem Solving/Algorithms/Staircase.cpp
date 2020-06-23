#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) 
{
    for(int i = 1, j = n; i <= n; i++, j--)
    {
        cout << setfill(' ') << setw(j) << '#';
        cout << setfill('#') << setw(i) << ' ';
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
