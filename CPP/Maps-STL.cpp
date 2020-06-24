#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <sstream> // string stream
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map<string,int> students;
    map<string,int>::iterator it;
    stringstream ss;
    string line;
    string name; 
    int q = 0;
    int type = 0;
    int mark = 0;      

    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for(int i = 0; i < q; i++)
    {        
        ss.clear(); // Clear stringstream to reuse with new line input
        getline(cin, line);
        ss.str(line);

        ss >> type;
        
        if(type == 1) // Add the marks Y to the student whose name is X.
        {
            ss >> name >> mark;             
            it = students.find(name);            
            if(it != students.end()) // If the student exists, updates mark
            {
                it->second += mark;   
            }
            else // Else add the student to the map
            {
                students[name] = mark;
            }
        }
        else if(type == 2) // Erase the marks of the students whose name is X
        {
            ss >> name;              
            it = students.find(name);            
            if(it != students.end())
            {
                it->second = 0;   
            }
        }
        else if(type == 3) // Print the marks of the students whose name is X
        {
            ss >> name;
            it = students.find(name);
            
            if(it == students.end()) // Key not found --> Student's mark = 0
            {
                cout << "0" << endl;  
            }
            else
            {
                cout << it->second << endl;
            }
        }
    }
    
    return 0;
}