#include <iostream>
using namespace std;

int count(int arr[],int size){
    int count[size] = {0};
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }
    cout<< count[0]<<endl;
    cout<< count[1]<<endl; 
    cout<< count[2]<<endl;

}

int main(){
    int arr[12]={0,1,2,2,1,1,0,0,0,1,1,2};
    count(arr,12);
    return 0;
}