#include <bits/stdc++.h>
#include <string>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) 
{
    char ch;
    int divisor = 0;
    int digits = 0;
    string num;
    stringstream ss;

    num = to_string(n);
    ss.str(num);

    for(int i = 0; i < num.size(); i++)
    {
        ss >> ch;
        divisor = ch-48; // USING ASCII: 0 = 48, 1 = 49,... 9 = 57

        if(divisor != 0 && n % divisor == 0)
        {
            digits++;
        }
    }

    return digits;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
