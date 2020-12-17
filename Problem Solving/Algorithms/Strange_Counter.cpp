#include <bits/stdc++.h>

using namespace std;

// PATTERN 01:
// The last 'time' of cycle 1 is: 3  = 3*1 = 3*(2^1-1)
// The last 'time' of cycle 2 is: 9  = 3*3 = 3*(2^2-1)
// The last 'time' of cycle 3 is: 27 = 3*7 = 3*(2^3-1)
// ...
// The last 'time' of cycle k is:          = 3*(2^k-1)

// PATTERN 02:
// Looking at cycle 2, the last 'time' of cycle is: lastTime = 9.
// Assume t = 3, then v(3) = lastTime - t + 1

// Complete the strangeCounter function below.
long strangeCounter(long t) 
{    
    long pow = 2; // Represents 2^k
    
    // Loop ends when it's the last 'time' of cycle, >= t
    while(3*(pow-1) < t)
    {
        pow *= 2; // Calculate 2^k
    }
    
    return 3*(pow-1) - t + 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
