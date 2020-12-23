#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr)
{
    int c = 0;
    int k = 0;
    int occur = 0;
    string minStr = "";
    int minSize = 100;

    // Loops through the vector of array to find shortest string
    for(int i = 0; i < arr.size(); i++)
    {
        if(minSize > arr[i].length())
        {
            minSize = arr[i].length();
            minStr = arr[i];
        }
    }

    // Remove duplicate characters in the shortest string    
    sort(minStr.begin(), minStr.end());

    // Loops through all elements of the string
    while(k < minStr.length())
    {
        // If two adjacent elements are the same, erase the duplicate
        if(minStr[k] == minStr[k+1])
        {
            minStr.erase(minStr.begin()+k);
            k = 0;
        }
        else // Else, increment to check the next element
        {
            k++;
        }
    }

    // Check for occurances compared to minStr
    for(int i = 0; i < minStr.length(); i++)
    {
        // Loop through check all strings from arr
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[j].find(minStr[i]) != -1)
            {
                occur++;
            }
        }

        // If the number of occurances equal the number of strings to compare
        if(occur == arr.size())
        {
            c++; // Increment the number of gem stones
        }

        occur = 0;
    }

    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
