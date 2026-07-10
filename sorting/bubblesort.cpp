#include <bits/stdc++.h>
using namespace std;

int bubblesort(int arr[],int n){
    for (int i =1;i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
    }
    }
}
int printarr(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int arr[15]={12,4,7,3,45,221,122,321,567,74333,664,65,32,31,21};
    bubblesort(arr,15);
    printarr(arr,15);   
    return 0;
}