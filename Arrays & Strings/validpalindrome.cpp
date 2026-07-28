#include <bits/stdc++.h>
using namespace std;

char palindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return 'N';
        }
        left++;
        right--;
    }
    return 'Y';
}

int main()
{
    string s = "racecar";
    cout << palindrome(s) << endl;
    return 0;
}