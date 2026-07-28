#include <iostream>
#include <climits>
using namespace std;

// function to get the maximum value in the array
int getmax(int num[],int size){
    int max= INT_MIN;//contains the minimum value of integer
    for (int i=0;i<size;i++){
        if(num[i]>max){
            max=num[i];
        }

    }
    return max;
}

// function to get the minimum value in the array
int getmin(int num[],int size){
    int min= INT_MAX;//contains the maximum value of integer
    for(int i=0;i<size;i++){
        if(num[i]<min){
            min=num[i];
        }
    }
    return min;
}


int main(){
    int size;
    cout<<"Enter the size of the array "<<endl;
    cin>>size;
    int num[1000];
    cout<<"Enter the elements of the array "<<endl;
    for(int i=0;i<size;i++){
        cin>>num[i];
    }

    cout<<"Maximum value for the array is "<<getmax(num,size)<<endl;
    cout<<"Minimum value for the array is "<<getmin(num,size)<<endl;
}
