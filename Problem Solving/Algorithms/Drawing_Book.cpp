#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(  int n, // number of pages in the book 
                int p) // page to turn to
{
    int cFront = 0;
    int cBack = 0;

    // If page to turn is start page (p = 1), count = 0
    // If page to turn is end page (p = n), count = 0
    // If p and n are in the same turn, i.e. [4|5], count = 0
    if(p == 1 || p == n || p/2 == n/2)
    {
        return 0;
    }
    else 
    {
        // n-p is the number of pages counting from the BACK
        // divided by 2 to get t, the number of turns from the BACK
        cBack = (n-p)/2;

        // p is the number of pages counting from the FRONT
        // divided by 2 to get c, the number of turns from the FRONT
        cFront = p/2;

        // If n and p's difference is 1 and in different turn, i.e. [_|1][2|3]
        if(cBack == 0)
        {
            return 1;
        }        

        // Check and return whichever one takes less turns
        if(cFront < cBack)
        {
            return cFront;
        }
        else
        {
            return cBack;
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
