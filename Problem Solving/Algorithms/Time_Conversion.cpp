#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

// Complete the timeConversion function below.
string timeConversion(string s) 
{
    stringstream sstream;
    string hhs, mms, sss, ampm; 
    char ch;
    int hh = 0; 
    int mm = 0;
    int ss = 0;   

    sstream.str(s);
    sstream >> hh >> ch >> mm >> ch >> ss >> ampm;

    if(ampm == "PM")
    {
        if(hh < 12)
        {
            hh += 12;
        }
    }
    else if (ampm == "AM")
    {
        if(hh == 12)
        {
            hh = 0;
        } 
    }    
    
    if(hh < 10) 
    {
        hhs = "0" + to_string(hh);
    }
    else 
    {
        hhs = to_string(hh);
    }

    if(mm < 10)
    {
        mms = "0" + to_string(mm);
    }
    else 
    {
        mms = to_string(mm);
    }
    
    if(ss < 10)
    {
        sss = "0" + to_string(ss);
    }
    else 
    {
        sss = to_string(ss);
    }
    
    return hhs + ch + mms + ch + sss;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
