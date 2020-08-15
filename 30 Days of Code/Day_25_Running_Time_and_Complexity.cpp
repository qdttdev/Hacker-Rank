#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int testCases = 0;
    int testInput = 0;    

    cin >> testCases;

    for(int i = 0; i < testCases; i++)
    {        
        cin >> testInput;

        if(testInput <= 1)
        {
            cout << "Not prime\n";
        } 
        else 
        {
            int count = 0;
            
            // We only need to check for divisors up to the squareroot of n 
            // to determine if the number is a prime number
            for(int j = 2; j <= sqrt(testInput); j++)
            {
                if(testInput % j == 0)
                {
                    count++;
                    break;
                }
            }

            if(count > 0)
            {
                cout << "Not prime\n";
            }
            else 
            {
                cout << "Prime\n";
            }
        }
    }

    return 0;
}
