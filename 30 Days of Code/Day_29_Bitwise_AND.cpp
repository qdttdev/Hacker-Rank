#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N = 0;
    int K = 0;
    int T = 0;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> N >> K;
        int max = 0;
        int result = 0;

        // Objective: We have to find "a & b" value so that
        // a, b are elements of S = {1, 2, 3, ..., N} where "a < b" and "a & b < K"
        for(int a = 0; a <= N; a++)
        {
            for(int b = a + 1; b <= N; b++)
            {
                result = a & b;

                if(result > max && result < K)
                {
                    max = result;
                }
            }
        }

        cout << max << endl;
    }

    return 0;
}
