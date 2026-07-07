#include <iostream>
using namespace std;

// void swapalternative(int arr[],int size){
//     int f=0;
//     int s=1;
//     while(s<size){
//         swap(arr[f],arr[s]);
//         f+=2;
//         s+=2;
//     }
// }
void swapalternative(int arr[],int size){
    for(int i=0;i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    }
}

int main(){
    int arr[7]={1,2,3,4,5,6,7};
    int arr2[6]={1,2,3,4,5,6};
    swapalternative(arr,7);
    swapalternative(arr2,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<6;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
}