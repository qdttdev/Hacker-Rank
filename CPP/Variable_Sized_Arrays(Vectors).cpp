#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    vector<vector<int>> rowArray;
    int rowArraySize = 0;
    int queries = 0;
    int colArraySize = 0;
    int elem = 0;
    int rowIndex = 0;
    int colIndex = 0; 

    // Get first line inputs
    cin >> rowArraySize;
    cin >> queries;

    // Populates rowArrays
    for(int i = 0; i < rowArraySize; i++)
    {        
        cin >> colArraySize;
        vector<int> colArray;

        // Populates colArrays
        for(int j = 0; j < colArraySize; j++)
        {            
            cin >> elem;
            colArray.push_back(elem);
        }

        // Push colArray element into rowArray
        rowArray.push_back(colArray);
    }

    // Get positions and print
    for(int count = 0; count < queries; count++)
    {
        cin >> rowIndex;
        cin >> colIndex;

        cout << rowArray[rowIndex][colIndex] << endl;
    }

    return 0;
}
