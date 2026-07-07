#include <iostream>
using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort01(int arr[],int size){

    int left=0,right=size-1;
    while (left<right)
    {
    while(arr[left]==0 && left<right){
        left++;

    }
    while(arr[right]==1 && left<right){
        right--;
    }
    if(left<right){
        swap(arr[left],arr[right]);
        left++;right--;
    }
    
}
}


int main (){
    int arr[10]={0,1,0,1,0,1,0,1,0,1};
    print(arr,10);
    sort01(arr,10);
    print(arr,10);
    return 0;
}