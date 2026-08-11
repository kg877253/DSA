#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n){

        int count = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i < n; i++){

            if (prime[i])
            {
                count++;
                for (int j = i * 2; j < n; j = j + i)
                {
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};

int main()
{
    int n;
    cout << "enter a number: ";
    cin >> n;
    Solution prime;
    cout << "count of prime numbers: " << prime.countPrimes(n) << endl;
    return 0;
}