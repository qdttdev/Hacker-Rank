#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int size = 0;
    int *dynamicArray;

    cin >> size;
    cin.ignore();

    dynamicArray = new int[size];

    for(int i = 0; i < size; i++)
    {
        cin >> dynamicArray[i];
    }

    for(int i = size-1; i >= 0; i--)
    {
        cout << dynamicArray[i] << " ";
    }

    return 0;
}
