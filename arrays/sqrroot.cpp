#include <bits/stdc++.h>
using namespace std;
long long binaryroot(int n)
{
    int s = 0;
    int e = n;
    long long ans = -1;
    while (s <= e)
    {

        long long mid = s + (e - s) / 2;
        long long square = mid * mid;

        if (square == n)
        {
            return mid;
        }
        else if (square > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}

double moredecimal(int n, int precision, int tempsol){
    double factor=1;
    double ans=tempsol;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;

}


int main()
{
    int n;
    cout<<"Enter the number to find the square root of: ";
    cin >> n;
    int tempsol = binaryroot(n);
    cout << binaryroot(n) << endl;
    cout << moredecimal(n, 4, tempsol) << endl;
    return 0;
}