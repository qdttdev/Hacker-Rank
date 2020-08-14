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

    if(d <= dd && m <= mm && y <= yy)
    {
        fine = 0;
    }
    else if(d > dd && m == mm && y == yy)
    {
        fine = 15 * (d - dd);
    }
    else if(m > mm && y == yy)
    {
        fine = 500 * (m - mm);
    }
    else if(y > yy)
    {
        fine = 10000;
    }

    cout << fine;

    return 0;
}
