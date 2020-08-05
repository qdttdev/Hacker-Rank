#include <bits/stdc++.h>

using namespace std;

// FAILS 9/12 test cases, doesn't handle RRRR, BBB

// Complete the happyLadybugs function below.
string happyLadybugs(string b) 
{
    string yesNo = "YES";
    bool isEmpty = false;
    bool isSingle = false;

    // If there's an empty space, it's movable
    for(int i = 0; i < b.size(); i++)
    {
        if(b[i] == '_')
        {
            isEmpty = true;
            break;
        }
    }

    // Sort the elements for possible pairs
    if(isEmpty)
    {
       sort(b.begin(),b.end()); 
    }
    else 
    {
        if(b[0] != b[1] || b[b.size()-1 != b[b.size()-2]])
        {
            isSingle = true;
        }
    }

    // Check for singles
    for(int i = 1; i < b.size()-1; i++)
    {
        if(b[i] != b[i-1] && b[i] != b[i+1])
        {
            isSingle = true;
        }   
    }

    cout << "STRING " << b << endl;
    
    if(isEmpty == true && isSingle == false)
    {
        yesNo = "YES";
        cout << yesNo << endl;
        cout << isEmpty << " " << isSingle << endl << endl;
    }
    else if(isEmpty == true && isSingle == true)
    {
        yesNo = "NO";
        cout << yesNo << endl;
        cout << isEmpty << " " << isSingle << endl << endl;
    }
    else if(isEmpty == false && isSingle == true)
    {
        yesNo = "NO";
        cout << yesNo << endl;
        cout << isEmpty << " " << isSingle << endl << endl;
    }
    else 
    {
        yesNo = "N/A";
        cout << yesNo << endl;
        cout << isEmpty << " " << isSingle << endl << endl;
    }

    return yesNo;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < g; i++) 
    {
        int n = 0;
        string b = "";

        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');        
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
