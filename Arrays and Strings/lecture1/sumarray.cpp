#include <iostream>
using namespace std;
int arraysum(int arr[],int size){
    int sum=0;
    for (int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int size;
    cout<<"enter size of the array"<<endl;
    cin>>size;
    int arr[1000];
    cout<<"Enter element of the array:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    
    }
    cout<<"Sum of the array is :"<< arraysum(arr,size)<<endl;

    return 0;
}