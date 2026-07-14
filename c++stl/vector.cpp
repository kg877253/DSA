#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec1={2,3,5,6};
    //both are same 
    vec1.push_back(4);
    vec1.emplace_back(7);
    for(int val:vec1){
        cout<<val<<" ";
    }
    cout<<endl;

    // cout<<"at 1 "<<vec1.at(1)<<endl;;
    // cout<<vec1[1];
    vec1.pop_back();
    for(int val:vec1){
        cout<<val<<" ";
        
    }
    cout<<endl;

    vector<int>::iterator i;
    for(i=vec1.begin();i!=vec1.end();i++){
        cout<<*(i)<<" ";
    }
    //*(i) dereferences the iterator to get the actual value at that position.

    
    return 0;
}