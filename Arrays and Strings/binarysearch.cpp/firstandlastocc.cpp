#include <iostream>
using namespace std;

int firstocc(int arr[],int n,int k){
    int start=0;
    int end=n-1;
    int ans=-1;
    
    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==k){
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]<k){
        start=mid+1;
        }
        else if(arr[mid]>k){
        end=mid-1;
        }
            
        
    }
    
    return ans;
}

int lastocc(int arr[],int n,int k){
    int start=0;
    int end=n-1;
    int ans=-1;
    
    
    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==k){
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]<k){
            start=mid+1;
        }
        else if(arr[mid]>k){
            end=mid-1;
        }
            
        
    }
    
    return ans;
}


int main(){
    int arr[10]={1,1,2,3,3,3,3,3,4,5};
    
    cout<<"this is the first occ of 3 "<<firstocc(arr,10,3)<<endl;
    cout<<"this is the last occ of 3 "<<lastocc(arr,10,3)<<endl;
    
}