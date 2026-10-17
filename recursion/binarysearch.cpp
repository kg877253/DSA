#include <iostream>
using namespace std;

bool binarysearch(int *arr, int s, int e, int key){
    // Base case
    if(s>e) return false;

    int mid= s+(e-s)/2;
    //element found
    if(arr[mid]==key) return true;

    // Recursive cases
    if(arr[mid]<key) {
        return binarysearch(arr, mid+1,e,key);
    }
    else{
        return binarysearch(arr,s, mid-1,key);
    }
}

int main(){
    int arr[6]={3,4,7,8,28,13};
    int key=28;

    if(binarysearch(arr,0,5,key)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    return 0;
}