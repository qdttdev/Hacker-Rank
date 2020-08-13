#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};

class Calculator : public AdvancedArithmetic 
{
    private:
    public:
        vector<int> findAllDivisor(int n)
        {
            vector<int> divisors;

            for(int i = 1; i <= n; i++) // starts @ 1 because not divisible by 0
            {
                if(n % i == 0) // if divisible
                {
                    divisors.push_back(i);
                }
            }

            return divisors;
        }

        int divisorSum(int n) 
        {
            vector<int> divList = findAllDivisor(n);
            int sum = 0;

            for(int i = 0; i < divList.size(); i++)
            {
                sum += divList[i];
            }

            return sum;
        }
};

int main(){
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator(); 
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}
