#include <iostream>
using namespace std;

void findnumber(int arr[],int size,int number){
    for(int i=0;i<size;i++){
        if(arr[i]==number){
            cout<<"yes "<<number<<" is present in this array at index "<< i <<endl;
            return;
        }
    }
    cout<<"no "<<number<<" is not present in this array "<<endl;
}





int main(){
    
    int arr[8]={12,54,-65,7,8,9,43,0};
    //find if 9 is present in the array or not
    int number;
    cout<<"Enter the number to find in the array "<<endl;
    cin>>number;
    findnumber(arr,8,number);
}