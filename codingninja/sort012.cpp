#include <iostream>
using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort012(int arr[],int size){
    int low=0, mid=0, high=size-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main (){
    int arr[12]={0,1,2,2,1,1,0,0,0,1,1,2};
    print(arr,12);
    sort012(arr,12);
    print(arr,12);
    return 0;
}
