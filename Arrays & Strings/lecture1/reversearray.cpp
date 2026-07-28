#include <iostream>
using namespace std;
//by swaping
int reversearray(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
//normal method
// int reversearray(int arr[],int size){
//     for(int i= size-1;i>=0;i--){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[5]={1,2,3,4,5};
    reversearray(arr,5);
    printarray(arr,5);
}