#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,2,3,4};
    int n = nums.size();
    vector<int> ans(n,1);

    int prefix=1;
    for(int i=0;i<n;i++){
        ans[i]=prefix;
        prefix*=nums[i];
    }

    int suffix=1;
    for(int i=n-1;i>=0;i--){
        ans[i]*=suffix;
        suffix*=nums[i];
    }

    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}
