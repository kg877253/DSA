#include <bits/stdc++.h>
using namespace std;

void saydigits(int n, string arr[])
{

    if (n == 0)
        return;

    int digit = n % 10;
    n = n / 10;
    saydigits(n, arr);
    cout << arr[digit] << " ";
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << "Digits in words: ";
    saydigits(n, arr);
    cout << endl;
    
    return 0;
}