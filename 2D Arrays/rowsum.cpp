#include <bits/stdc++.h>
using namespace std;

//to calc row wise sum of 2D array
// void rowwisesum(int arr[][3],int row,int col){
//     for(int row =0;row<3;row++){
//         int sum=0;
//         for(int col=0;col<3;col++){
//             sum+=arr[row][col];
//         }
//         cout<<sum<<" ";
//     }
// }

//to calc highest row sum of 2D array
void rowwisehighsum(int arr[][4],int row,int col){
    int maxi=-1;
    int rowindex=-1;

    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<4;col++){
            sum+=arr[row][col];
        }

        if(sum>maxi){
            maxi=sum;
            rowindex=row;
        }
    }
    cout<<"highest row sum is "<<maxi<<" and its index is "<<rowindex<<endl;
}


int main() {
    int arr[3][4];

    cout<<"enter the elements of the array"<<endl;

    for(int row =0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    cout<<endl;

    //print the 2D array
    for(int i =0 ;i<3; i++){
        for(int j = 0 ; j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // rowwisesum(arr, 3, 3);
    rowwisehighsum(arr, 3, 4);
    return 0;
}