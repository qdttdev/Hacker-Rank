#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int  minimumNumber(int n, string password) 
{
    const int MIN_CHAR = 6;

    int numCount = 0;
    int lowerCaseCount = 0;
    int upperCaseCount = 0;
    int specialCharCount = 0;

    int min = 0;
    int length = n;

    for(int i = 0; i < password.length(); i++)
    {
        if(isdigit(password[i]))
        {
            numCount++;
        }
        else if(islower(password[i]))
        {
            lowerCaseCount++;
        }
        else if(isupper(password[i]))
        {
            upperCaseCount++;
        }
        else 
        {
            specialCharCount++;
        }
    }

    if(numCount == 0)
    {
        min++;
        length++;
    }
    if(lowerCaseCount == 0)
    {
        min++;
        length++;
    }
    if(upperCaseCount == 0)
    {
        min++;
        length++;
    }
    if(specialCharCount == 0)
    {
        min++;
        length++;
    }

    if(length < MIN_CHAR)
    {
        min += MIN_CHAR - length;
    }

    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
