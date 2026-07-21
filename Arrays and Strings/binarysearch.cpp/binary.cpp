#include <iostream>
using namespace std;

int binarysearch(int arr[],int size,int key){
    
    int start=0;
    int end=size-1;

    
    while(start<=end){
        //also we can use int mid=(start+end)/2; but it may exceed the range of integer if start and end are large numbers
        int mid = start + (end - start) / 2;
        
        if(arr[mid]==key){
            return mid;
        }
        //go to righ part
        if(arr[mid]<key){
            start=mid+1;       
        }
        //go to left part
        if(arr[mid]>key){
            end=mid-1;
        }
        
    }
    return -1;
}


int main(){
    int evenarr[5]={2,4,6,8,10};
    int oddarr[6]={1,3,5,6,9,17};

    int indexe=binarysearch(evenarr,5,10);
    cout<<"The index of 10 is "<< indexe<<endl;

    int indexo=binarysearch(oddarr,6,17);
    cout<<"The index of 17 is "<< indexo<<endl;


}