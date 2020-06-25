#include <bits/stdc++.h>

using namespace std;

// 8
// UD DD UD UU = 1 valley
//
//              
//  /\          
//    \    /    
//     \/\/     

// 10
// UD UU UD UD DD = 0 valley
//
//     /\/\
//    /    \
// /\/      \

// 10
// DU DD DU UD UU = 2 valleys
//
//  \/\      /
//     \  /\/
//      \/

// 12
// DD UU DD UD UU UD = 2 valleys
//                  
//            /\    
//  \  /\    /      
//   \/  \/\/       

// Complete the countingValleys function below.
int countingValleys(int n, string s) 
{
    int valley = 0;
    int seaLevel = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'U')
        {
            seaLevel++;
        }
        else 
        {
            seaLevel--;
        }

        // Valley = ending with a step up to sea level
        if(seaLevel == 0 && s[i] == 'U')
        {
            valley++;
        }
    }

    return valley;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
