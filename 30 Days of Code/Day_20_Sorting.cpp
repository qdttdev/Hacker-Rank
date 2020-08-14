#include <bits/stdc++.h>

using namespace std;

int main() 
{    
    int n = 0;
    int swaps = 0;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }

    // Write Your Code Here
    for (int i = 0; i < n; i++) 
    {       
        for (int j = 0; j < n - 1; j++) 
        {
            if (a[j] > a[j + 1]) // Swap if not in order
            {
                swap(a[j], a[j + 1]);
                swaps++;
            }
        }
        
        if (swaps == 0) // No swaps mean already sorted
        {
            // break;
        }    
    }

    cout << "Array is sorted in " << swaps << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size()-1] << endl;

    return 0;
}
