#include <bits/stdc++.h>
using namespace std;

bool issorted(int arr[],int n ){
    if(n==1 || n==0){
        return true;
    }
    if(arr[n-1] < arr[n-2]){
        return false;
    }
    return issorted(arr, n-1);
}

int main() {

    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 3, 2, 22,11};
    issorted(arr, 5) ? cout << "Array is sorted"<< endl : cout << "Array is not sorted"<< endl;
    issorted(arr2, 5) ? cout << "Array is sorted"<< endl : cout << "Array is not sorted" << endl;
    
    return 0;
}