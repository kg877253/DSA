#include <bits/stdc++.h>
using namespace std;

int sum(int arr[],int n){
    if(n==0) return 0;
    if(n==1) return arr[0];
    int sume= arr[n-1] + sum(arr, n-1);
    return sume;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 115};
    cout << "Sum of array elements: " << sum(arr, 5) << endl;
    return 0;
}