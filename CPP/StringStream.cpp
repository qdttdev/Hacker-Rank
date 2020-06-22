#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

// METHOD #1
vector<int> parseInts(string str) 
{    
    vector<int> outputAr;
    stringstream ss(str);
    string temp2;

    while(getline(ss, temp2, ',')) // getline(input_stream, string, delim)
    {
        outputAr.push_back(stoi(temp2)); 
    }

    return outputAr;
}

int main() 
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

// METHOD #2
// vector<int> parseInts(string str) 
// {
//     vector<int> outputAr;
//     stringstream ss(str);
//     int temp;
//     char ch;
//
//     while(!ss.eof())
//     {
//         if(ss >> temp)
//         {
//             outputAr.push_back(temp);
//         }
//         ss >> ch;          
//     }
//     
//      return outputAr;
// }