#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int entries = 0;
    string nameToFind = "";
    string name = "";
    string cel = "";
    map<string,string> phoneBook;

    cin >> entries;
    cin.ignore(numeric_limits <streamsize>::max(), '\n');

    for(int i = 0; i < entries; i++)
    {
        cin >> name >> cel;
        phoneBook[name] = cel;
    }

    while(cin.ignore())
    {
        cin >> nameToFind;
        auto it = phoneBook.find(nameToFind);

        if(it == phoneBook.end())
        {
            cout << "Not found" << endl;
        } 
        else
        {
            cout << it->first << "=" << it->second << endl;
        }
    }

    return 0;
}
