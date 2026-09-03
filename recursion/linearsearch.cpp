#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    cout << "size of array: " << n << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool linearsearch(int arr[], int n, int k){

    print(arr, n);
    if (n == 0)
        return false;
    if (arr[0] == k)
        return true;
    bool remainingpart = linearsearch(arr + 1, n - 1, k);

    return remainingpart;
}

int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    int key = 4;

    linearsearch(arr, 5, key) ? cout << "Element found" << endl : cout << "Element not found" << endl;

    return 0;
}