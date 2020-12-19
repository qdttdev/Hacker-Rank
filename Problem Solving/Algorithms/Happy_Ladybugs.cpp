#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b)
{
    bool movable = false;
    string output = "YES";

    // Check if there's an empty space = movable
    for(int i = 0; i < b.length(); i++)
    {
        if(b[i] == '_')
        {
            movable = true;
            break;
        }
    }

    // If the string length is greater than 1, proceed to check
    if(b.length() > 1)
    {
        if(!movable) // If not movable, compare adjacent elements
        {
            for(unsigned int i = 1; i < b.length(); i++)
            {
                // If the first element is single, or any other than '_' is single
                if((b[0] != b[1]) || (b[i] != b[i-1] && b[i] != b[i+1] && b[i] != '_'))
                {
                    output = "NO";
                }
            }
        }
        else // Else if movable, sort and compare adjacent elements
        {
            sort(b.begin(),b.end());

            for(unsigned int i = 1; i < b.length(); i++)
            {
                // If the first element is single, or any other than '_' is single
                if((b[0] != b[1]) || (b[i] != b[i-1] && b[i] != b[i+1] && b[i] != '_'))
                {
                    output = "NO";
                }
            }
        }
    }
    else if(b[0] != '_') // If string length is less than 1 and first elem is a bug
    {
        output = "NO";
    }

    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
