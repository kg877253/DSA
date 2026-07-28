#include <bits/stdc++.h>
using namespace std;

vector<int> revarrfromm(vector<int> arr, int m) {

    int start=m+1;
    int end=arr.size()-1;

    while(start<=end){
        
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    return arr;
}
void printarr(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {

    vector<int> arr={1,2,3};

    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);

    vector<int> ans= revarrfromm(arr,3);
    printarr(ans);
    return 0;
}