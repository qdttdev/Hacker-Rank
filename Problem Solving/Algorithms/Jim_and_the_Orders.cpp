#include <bits/stdc++.h>

using namespace std;

// Driver function to sort the 2D vector base on 3rd column 
bool sortCol3(const vector<int>& v1, const vector<int>& v2) 
{ 
    return v1[2] < v2[2]; 
} 

// Complete the jimOrders function below.
vector<int> jimOrders(vector<vector<int>> orderPrep) // [order[i],prep[i]]
{
    // Note: Sizing vector when declaring --> orderServe(rowSize, colSize)
    vector<vector<int>> orderServe(orderPrep.size(), vector<int>(3));
    vector<int> orderDelivered;

    // Populate orderServe: [customer[i], order[i], serveTime[i]]
    for(int i = 0; i < orderServe.size(); i++)
    {        
        orderServe[i][0] = i+1;
        orderServe[i][1] = orderServe[i][0];
        orderServe[i][2] = orderPrep[i][0] + orderPrep[i][1];
    }

    // Sort orderServe array by serveTime at column 3
    sort(orderServe.begin(), orderServe.end(), sortCol3);

    // Handle case at the same serveTime to follow order # 
    for(int i = 0; i < orderServe.size() - 1; i++)
    {
        if((orderServe[i][2] == orderServe[i+1][2])
        && (orderServe[i][1] > orderServe[i+1][1]))
        {
            swap(orderServe[i][0],orderServe[i+1][0]);
            swap(orderServe[i][1],orderServe[i+1][1]);
            swap(orderServe[i][2],orderServe[i+1][2]);
        }
    }

    // Populate orderDeliver array
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
