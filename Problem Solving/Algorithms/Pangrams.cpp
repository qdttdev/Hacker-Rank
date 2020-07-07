#include <bits/stdc++.h>

using namespace std;

// We promptly judged antique ivory buckles for the next prize  --> pangram
// We promptly judged antique ivory buckles for the prize       --> not pangram: 'x'

// Complete the pangrams function below.
string pangrams(string s) 
{
    string pangram = "pangram";
    transform(s.begin(), s.end(), s.begin(), :: tolower); 

    map<char,int> letters = {
                                {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0},
                                {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0},
                                {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0},
                                {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0},
                                {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
                                {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0},
                                {'y', 0}, {'z', 0},
                            };

    for(int i = 0; i < s.size(); i++)
    {
        switch(s[i])
        {
            case 'a':   letters['a']++;
                        break;
            case 'b':   letters['b']++;
                        break;
            case 'c':   letters['c']++;
                        break;
            case 'd':   letters['d']++;
                        break;
            case 'e':   letters['e']++;
                        break;
            case 'f':   letters['f']++;
                        break;
            case 'g':   letters['g']++;
                        break;
            case 'h':   letters['h']++;
                        break;
            case 'i':   letters['i']++;
                        break;
            case 'j':   letters['j']++;
                        break;
            case 'k':   letters['k']++;
                        break;
            case 'l':   letters['l']++;
                        break;
            case 'm':   letters['m']++;
                        break;
            case 'n':   letters['n']++;
                        break;
            case 'o':   letters['o']++;
                        break;
            case 'p':   letters['p']++;
                        break;
            case 'q':   letters['q']++;
                        break;
            case 'r':   letters['r']++;
                        break;
            case 's':   letters['s']++;
                        break;
            case 't':   letters['t']++;
                        break;
            case 'u':   letters['u']++;
                        break;
            case 'v':   letters['v']++;
                        break;
            case 'w':   letters['w']++;
                        break;
            case 'x':   letters['x']++;
                        break;
            case 'y':   letters['y']++;
                        break;
            case 'z':   letters['z']++;
                        break;
        }
    }

    auto it = letters.begin();

    while(it != letters.end())
    {
        if(it->second == 0)
        {            
            pangram = "not pangram";
            break;
        }

        it++;
    }

    return pangram;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
