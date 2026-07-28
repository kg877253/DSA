#include <iostream>
using namespace std;

void swap(int arr[],int size){
    int temp=0;
    for(int i=0;i<size;i+=2){
        if(i+1<size){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
}

int main(){
    int arr[6]={1,2,3,4,5,6};
    swap(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}
