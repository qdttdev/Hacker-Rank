#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    
    int i = 0;
    long l = 0;
    char ch;
    float f = 0;
    double d = 0;

    cin >> i;
    cin >> l;
    cin >> ch;
    cin.ignore();
    cin >> f;
    cin >> d;
    
    cout << i << endl;
    cout << l << endl;
    cout << ch << endl;

    cout << fixed;
    cout << setprecision(3);
    cout << f << endl;

    cout << setprecision(9);
    cout << d << endl;

    return 0;
}
