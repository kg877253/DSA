#include <bits/stdc++.h>
using namespace std;

int selectionsort(int arr[],int n ){

    for(int i =0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){

            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
    
}
int printarr(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main() {

    int arr[12]={12,4,7,3,45,221,433,664,65,32,31,21};
    selectionsort(arr,12);
    printarr(arr,12);
    return 0;
}