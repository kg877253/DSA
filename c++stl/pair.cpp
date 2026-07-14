#include <iostream>
#include <vector>
using namespace std;

int main() {
    // pair<int,int> p={1,3};
    // cout<<p.first;
    // cout<<" "<<p.second;

    //WE CAN MAKE PAIR OF ANYTHING INT,FLOAT,CHAR,STRING,ETC.

    // pair<int,string> p2={2,"kartik"};
    // cout<<p2.first;
    // cout<<" "<<p2.second;

    // pair<int,pair<int,char>> p3={2,{3,'k'}};
    // cout<<p3.first;
    // cout<<" " << p3.second.first << " " << p3.second.second;
    
    vector<pair<int,int>> vec={{1,2},{3,4},{5,6}};

    vec.push_back({7,8});
    //same but we don't have to give paranthesis in emplace op. it takes automatically.
    vec.emplace_back(9,10);
    for(auto val:vec){
        cout<<val.first;
        cout<<val.second<<" ";
    }
    return 0;
}