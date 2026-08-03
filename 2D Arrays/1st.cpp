#include <bits/stdc++.h>
using namespace std;

int main() {
    //create a 2D array of size 3x4
    int arr[3][4];

    //input values into the 2D array
    for(int i =0 ;i<3; i++){
        for(int j = 0 ; j<4;j++){
            cin>>arr[i][j];
        }
    }
    for(int i =0 ;i<3; i++){
        for(int j = 0 ; j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}