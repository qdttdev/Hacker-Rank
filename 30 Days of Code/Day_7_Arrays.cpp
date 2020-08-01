#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int main()
{
    vector<int> a;
    int length;
    int input;
    
    cin >> length;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(int i = 0; i < length; i++)
    {
        cin >> input;
        a.push_back(input);
    }

    for(int i = length - 1; i >= 0; i--)
    {
        cout << a[i] << " ";
    }

    return 0;
}

    
