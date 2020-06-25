#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {

    map<int,int> daysOfMonth {
        {1, 31}, {2, 28},{3, 31}, {4, 30},
        {5, 31}, {6, 30},{7, 31}, {8, 31},
        {9, 30}, {10, 31}, {11, 30},{12, 31}
    };

    string dd, mm, dayOutput;    
    int const theDay = 256;
    bool isLeapYear = false;
    int daysCount = 0;
    int day = 0;
    int month = 0;

    if(year == 1918) // Julian -> Gregorian: 02/14 follows 01/31 -> loses 13 days
    {
        daysCount = -13;
    }
    else if(year < 1918) // Julian calendar
    {
        if(year % 4 == 0)
        {
            isLeapYear = true;
        }
    }
    else // Gregorian calendar
    {
        if(year % 400 == 0 || (year % 4 == 0) && (year % 100 != 0))
        {
            isLeapYear = true;
        }
    }       
    
    if(isLeapYear)
    {
        daysCount = 1;
    }

    // cout << "Leap year: +" << daysCount << endl;

    while(daysCount + daysOfMonth[month] < theDay)
    {
        daysCount += daysOfMonth[month];
        month++;

        // cout << "#" << daysCount  
        //      << "\tMonth = " << month << " (" << daysOfMonth[month] << ")"
        //      << "\tLeftover = " << theDay - daysCount << endl;
    }
    
    // cout << theDay-daysCount << " " << month << " " << year << endl;
    day = theDay - daysCount;

    if(day < 10)
    {
        dd = "0" + to_string(day);
    }
    else
    {
        dd = to_string(day);
    }

    if(month < 10)
    {
        mm = "0" + to_string(month);
    }
    else
    {
        mm = to_string(month);
    }

    dayOutput = dd + "." + mm + "." + to_string(year);    

    return dayOutput;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
