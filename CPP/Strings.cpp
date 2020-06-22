#include <iostream>
#include <string>
using namespace std;

int main() {

    string strA;
    string strB;
    char temp;

	getline(cin, strA);
    getline(cin, strB);

    cout << strA.length() << " " << strB.length() << endl;
    cout << strA << strB << endl;
    
    temp    = strA[0];  // temp = a         
    strA[0] = strB[0];  // a' = b
    strB[0] = temp;     // b' = a = temp

    cout << strA << " " << strB;

    return 0;
}