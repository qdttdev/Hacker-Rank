#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) 
{
    string hh = "";
    string mm = "";    

    switch(m) // 0 <= m < 60
    {
        case 0:     mm = "o\' clock";
        break;
        
        case 1:     mm = "one minute past";
        break;
        
        case 2:     mm = "two minutes past";
        break;

        case 3:     mm = "three minutes past";
        break;

        case 4:     mm = "four minutes past";
        break;
        
        case 5:     mm = "five minutes past";
        break;

        case 6:     mm = "six minutes past";
        break;

        case 7:     mm = "seven minutes past";
        break;
        
        case 8:     mm = "eight minutes past";
        break;

        case 9:     mm = "nine minutes past";
        break;

        case 10:    mm = "ten minutes past";
        break;
        
        case 11:    mm = "eleven minutes past";
        break;

        case 12:    mm = "twelve minutes past";
        break;

        case 13:    mm = "thirteen minutes past";
        break;
        
        case 14:    mm = "fourteen minutes past";
        break;

        case 15:    mm = "quarter past";
        break;

        case 16:    mm = "sixteen minutes past";
        break;
        
        case 17:    mm = "seventeen minutes past";
        break;

        case 18:    mm = "eighteen minutes past";
        break;

        case 19:    mm = "nineteen minutes past";
        break;
        
        case 20:    mm = "twenty minutes past";
        break;

        case 21:    mm = "twenty one minutes past";
        break;

        case 22:    mm = "twenty two minutes past";
        break;
        
        case 23:    mm = "twenty three minutes past";
        break;
        
        case 24:    mm = "twenty four minutes past";
        break;

        case 25:    mm = "twenty five minutes past";
        break;

        case 26:    mm = "twenty six minutes past";
        break;
        
        case 27:    mm = "twenty seven minutes past";
        break;

        case 28:    mm = "twenty eight minutes past";
        break;

        case 29:    mm = "twenty nine minutes past";
        break;
        
        case 30:    mm = "half past";
        break;

        case 31:    mm = "twenty nine minutes to";
                    h++;
        break;

        case 32:    mm = "twenty eight minutes to";
                    h++;
        break;
        
        case 33:    mm = "twenty seven minutes to";
                    h++;
        break;
        
        case 34:    mm = "twenty six minutes to";
                    h++;
        break;

        case 35:    mm = "twenty five minutes to";
                    h++;
        break;

        case 36:    mm = "twenty four minutes to";
                    h++;
        break;
        
        case 37:    mm = "twenty three minutes to";
                    h++;
        break;

        case 38:    mm = "twenty two minutes to";
                    h++;
        break;

        case 39:    mm = "twenty one minutes to";
                    h++;
        break;
        
        case 40:    mm = "twenty minutes to";
                    h++;
        break;

        case 41:    mm = "nineteen minutes to";
                    h++;
        break;

        case 42:    mm = "eightteen minutes to";
                    h++;
        break;
        
        case 43:    mm = "seventeen minutes to";
                    h++;
        break;
        
        case 44:    mm = "sixteen minutes to";
                    h++;
        break;

        case 45:    mm = "quarter to";
                    h++;
        break;

        case 46:    mm = "fourteen minutes to";
                    h++;
        break;
        
        case 47:    mm = "thirteen minutes to";
                    h++;
        break;

        case 48:    mm = "twelve minutes to";
                    h++;
        break;

        case 49:    mm = "eleven minutes to";
                    h++;
        break;
        
        case 50:    mm = "ten minutes to";
                    h++;
        break;

        case 51:    mm = "nine minutes to";
                    h++;
        break;

        case 52:    mm = "eight minutes to";
                    h++;
        break;
        
        case 53:    mm = "seven minutes to";
                    h++;
        break;
        
        case 54:    mm = "six minutes to";
                    h++;
        break;

        case 55:    mm = "five minutes to";
                    h++;
        break;

        case 56:    mm = "four minutes to";
                    h++;
        break;
        
        case 57:    mm = "three minutes to";
                    h++;
        break;

        case 58:    mm = "two minutes to";
                    h++;
        break;

        case 59:    mm = "one minute to";
                    h++;
        break;
    }

    switch(h) // 1 <= h <= 12
    {
        case 1:     hh = "one";
        break;
        
        case 2:     hh = "two";
        break;

        case 3:     hh = "three";
        break;

        case 4:     hh = "four";
        break;
        
        case 5:     hh = "five";
        break;

        case 6:     hh = "six";
        break;

        case 7:     hh = "seven";
        break;
        
        case 8:     hh = "eight";
        break;

        case 9:     hh = "nine";
        break;

        case 10:    hh = "ten";
        break;
        
        case 11:    hh = "eleven";
        break;

        case 12:    hh = "twelve";
        break;
    }

    if(m == 0)
    {
        return hh + " " + mm;
    }
    else
    {
        return mm + " " + hh;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
