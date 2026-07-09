#include <bits/stdc++.h>
using namespace std;

int pivotIndex(int arr[],int n){
     
    int tsum=0;
    for(int i =0;i<n;i++){
        tsum+=arr[i];
    }
    
    int lsum=0;
    for(int i = 0;i<n;i++){

        int rsum=tsum-lsum-arr[i];
        if(lsum==rsum){
            return i;
        }

        
        lsum+=arr[i];
        
    }
    return -1;

}


int main() {
    
    int arr[6]={1,7,3,6,5,6};
    cout << pivotIndex(arr, 6) << endl;
    return 0;
}