#include <bits/stdc++.h>
using namespace std;


bool ispresent(int arr[][4],int target ,int row,int column){

    for(int i =0;i<row;i++){

        for(int j =0;j<column;j++){

            if(arr[i][j]==target){
                return 1;
            }
        }
    }

    return 0;
}

int main() {

    //create a 2D array of size 3x4
    // int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12}; --> It will take input in row wise manner
    // int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}}; --> It will take input in row wise manner

    int arr[3][4];

    //input values into the 2D array

    for(int i =0 ;i<3; i++){

        for(int j = 0 ; j<4;j++){

            cin>>arr[i][j];
        }

    }
    
    //print the 2D array
    for(int i =0 ;i<3; i++){
        for(int j = 0 ; j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int target;
    cin>>target;

    if(ispresent(arr, target, 3, 4)){
        cout<<"Element found"<<endl;
    }

    else{
        cout<<"Element not found"<<endl;
    }
    
    return 0;
}