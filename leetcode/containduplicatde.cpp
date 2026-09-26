

// 217. Contains Duplicate
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
    public:
    bool containsduplicate(vector<int>& nums){
        unordered_set<int> seen;

        for(int i =0;i<nums.size();i++){
            int num = nums[i];
            if(seen.find(num)!=seen.end()){
                return true;
            }
            seen.insert(num);  
        }
        return false;
    }

};
 
int main(){
    Solution s;
    vector<int> nums = {1,3,2,4,5,5,10};
    cout<<s.containsduplicate(nums)<<endl;
}