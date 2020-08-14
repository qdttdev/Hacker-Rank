#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m = 0, d = 0, y = 0;        // Actual return
    int mm = 0, dd = 0, yy = 0;     // Expected return
    int fine = 0;

    cin >> d >> m >> y;
    cin >> dd >> mm >> yy;

    if(y > yy)
    {
        fine = 10000;
    }
    else if (y == yy) 
    {
        if(m > mm)
        {
            fine = 500 * (m - mm);
        }
        else if(m == mm)
        {
            if(d > dd)
            {
                fine = 15 * (d - dd);
            }
            else
            {
                fine = 0;
            }
        }
    }

    cout << fine;

    return 0;
}
