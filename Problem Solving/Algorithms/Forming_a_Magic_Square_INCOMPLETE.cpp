#include <bits/stdc++.h>

using namespace std;

// Current Problem: Cannot handle duplicate summing pair, i.e. when there's two pairs 2&8 and 2&8 in the matrix.

/********************************************************************

    EXAMPLE 
    5 3 4            8 3 4
    1 5 8    -->     1 5 9
    6 4 2            6 7 2

    EXAMPLE 0
    4 9 2            4 9 2
    3 5 7    -->     3 5 7
    8 1 5            8 1 6

    EXAMPLE 1
    4 8 2            4 9 2
    4 5 7    -->     3 5 7
    6 1 6            8 1 6

    PROBLEM RECOGNITION:     
    - The magic sum is 15.
    - The center of the 3x3 matrix is 5. 
    
    --> We have summing pairs of opposite elements with 5 as the center,
    their summation equals 10 (15 - 5 = 10). The summing pairs are:

    1 & 9
    2 & 8                                   O X O
    3 & 7           with the 3x3 matrix:    X 5 X
    4 & 6                                   O X O

    5 & 5 is not a pair because all elements [1,9] must exist in the matrix

    --> Recognize that Corner pairs (O) are 2 & 8 and 6 & 4, 
        making Wedge pairs (X) are 1 & 9 and 3 & 7.

    To solve this problem, we check for opposite elements:    
    EXAMPLE 1
    4 8 2            4 9 2
    4 5 7    -->     3 5 7
    6 1 6            8 1 6

    We have the following pairs:
    - Top left TO bottom right (\)  : 4 + 6 = 10    OK
    - Bottom left TO top right (/)  : 6 + 2 = 8     Corner pair --> 8 + 2
    - Left TO right (--)            : 4 + 7 = 11    Wedge  pair --> 3 + 7
    - Top TO bottom (|)             : 8 + 1 = 9     Wedge  pair --> 9 + 1

    Generally:
    [00 01 02]
    [10 11 12]
    [20 21 22]

    --> 11 is always 5
    --> 00 & 22, 02 & 20 are pairs 2 & 8 or 6 & 4
    --> 01 & 21, 10 & 12 are pairs 1 & 9 or 3 & 7

********************************************************************/

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) 
{
    int cost = 0;
    int temp = 0;
    
    if(s[1][1] != 5)
    {
        cost += abs(s[1][1] - 5);
        s[1][1] = 5;
    }

    //--------------------------------------------------------------
    if(s[0][0] + s[2][2] != 10) // (\) CORNER
    {
        switch(s[0][0])
        {
            case 2: cost += abs(s[2][2] - 8);
                    s[2][2] = 8;
                    break;

            case 4: cost += abs(s[2][2] - 6);
                    s[2][2] = 6;
                    break;

            case 6: cost += abs(s[2][2] - 4);
                    s[2][2] = 4;
                    break;

            case 8: cost += abs(s[2][2] - 2);
                    s[2][2] = 2;
                    break;
        }

        if(s[0][0] + s[2][2] != 10)
        {
            switch(s[2][2])
            {
                case 2: cost += abs(s[0][0] - 8);
                        s[0][0] = 8;
                        break;

                case 4: cost += abs(s[0][0] - 6);
                        s[0][0] = 6;
                        break;

                case 6: cost += abs(s[0][0] - 4);
                        s[0][0] = 4;
                        break;

                case 8: cost += abs(s[0][0] - 2);
                        s[0][0] = 2;
                        break;
            }
        }          
    }

    //--------------------------------------------------------------
    if(s[0][2] + s[2][0] != 10) // (/) CORNER
    {
        switch(s[0][2])
        {
            case 2: cost += abs(s[2][0] - 8);
                    s[2][0] = 8;
                    break;

            case 4: cost += abs(s[2][0] - 6);
                    s[2][0] = 6;
                    break;

            case 6: cost += abs(s[2][0] - 4);
                    s[2][0] = 4;
                    break;

            case 8: cost += abs(s[2][0] - 2);
                    s[2][0] = 2;
                    break;
        }

        if(s[0][2] + s[2][0] != 10)
        {
            switch(s[2][0])
            {
                case 2: cost += abs(s[0][2] - 8);
                        s[0][2] = 8;
                        break;

                case 4: cost += abs(s[0][2] - 6);
                        s[0][2] = 6;
                        break;

                case 6: cost += abs(s[0][2] - 4);
                        s[0][2] = 4;
                        break;

                case 8: cost += abs(s[0][2] - 2);
                        s[0][2] = 2;
                        break;
            } 
        }        
    }

    //--------------------------------------------------------------
    if(s[0][1] + s[2][1] != 10) // (|) WEDGE
    {
        switch(s[0][1])
        {
            case 1: cost += abs(s[2][1] - 9);
                    s[2][1] = 9;
                    break;

            case 3: cost += abs(s[2][1] - 7);
                    s[2][1] = 7;
                    break;

            case 7: cost += abs(s[2][1] - 3);
                    s[2][1] = 3;
                    break;

            case 9: cost += abs(s[2][1] - 1);
                    s[2][1] = 1;
                    break;
        } 

        if(s[0][1] + s[2][1] != 10)
        {
            switch(s[2][1])
            {
                case 1: cost += abs(s[0][1] - 9);
                        s[0][1] = 9;
                        break;

                case 3: cost += abs(s[0][1] - 7);
                        s[0][1] = 7;
                        break;

                case 7: cost += abs(s[0][1] - 3);
                        s[0][1] = 3;
                        break;

                case 9: cost += abs(s[0][1] - 1);
                        s[0][1] = 1;
                        break;
            }
        }        
    }

    //--------------------------------------------------------------
    if(s[1][0] + s[1][2] != 10) // (--) WEDGE
    {
        switch(s[1][0])
        {
            case 1: cost += abs(s[1][2] - 9);
                    s[1][2] = 9;
                    break;

            case 3: cost += abs(s[1][2] - 7);
                    s[1][2] = 7;
                    break;

            case 7: cost += abs(s[1][2] - 3);
                    s[1][2] = 3;
                    break;

            case 9: cost += abs(s[1][2] - 1);
                    s[1][2] = 1;
                    break;
        } 

        if(s[1][0] + s[1][2] != 10)
        {
            switch(s[1][2])
            {
                case 1: cost += abs(s[1][0] - 9);
                        s[1][0] = 9;
                        break;

                case 3: cost += abs(s[1][0] - 7);
                        s[1][0] = 7;
                        break;

                case 7: cost += abs(s[1][0] - 3);
                        s[1][0] = 3;
                        break;

                case 9: cost += abs(s[1][0] - 1);
                        s[1][0] = 1;
                        break;
            }
        }        
    }
    
    cout << endl;

    cout << s[0][0] << " " << s[0][1] << " " << s[0][2] << endl;
    cout << s[1][0] << " " << s[1][1] << " " << s[1][2] << endl;
    cout << s[2][0] << " " << s[2][1] << " " << s[2][2] << endl;

    cout << "COST: " << cost << endl;

    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
