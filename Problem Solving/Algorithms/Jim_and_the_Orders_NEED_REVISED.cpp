#include <bits/stdc++.h>

using namespace std;

// TEST CASE 7 doesn't work, suspecting sum value needs to hold a long instead of an int.

// Driver function to sort the 2D vector base on 2nd column 
bool sortCol(const vector<int>& v1, const vector<int>& v2) 
{ 
    return v1[1] < v2[1]; 
} 

// Complete the jimOrders function below.
vector<int> jimOrders(vector<vector<int>> orderPrep) // [order[i],prep[i]]
{
    // Note: Sizing vector when declaring --> orderServe(rowSize, colSize)
    vector<vector<int>> orderServe(orderPrep.size(), vector<int>(2)); // [customer[i],serve[i]]
    vector<int> orderDelivered;

    for(int i = 0; i < orderPrep.size(); i++)
    {        
        orderServe[i][0] = i+1;
        orderServe[i][1] = orderPrep[i][0] + orderPrep[i][1];
    }

    sort(orderServe.begin(), orderServe.end(), sortCol);

    for(int i = 0; i < orderPrep.size(); i++)
    {
        orderDelivered.push_back(orderServe[i][0]);
    }

    return orderDelivered;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> orders(n);
    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> orders[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = jimOrders(orders);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
