#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main() {

    // list<int> l1={1,2,3};
    // l1.push_back(4);
    // l1.push_back(5);
    // l1.push_front(0);

    // l1.pop_back();
    // l1.pop_front();
    // for(int val:l1){
    //     cout<<val<<" ";
    // }
    // cout<<endl;

//SAME FUNCTION IN BOTH BUT WE CANT ACCESS ANY RANDOM INDEX IN LIST BECAUSE IT IS LIKE DOUBLY LINKED LIST BUT WE CAN ACCESSS IN DEQUE.

    deque<int> d1={1,2,3};
    d1.push_back(4);
    d1.push_back(5);
    d1.push_front(0);

    d1.pop_back();
    d1.pop_front();
    
    for(int val:d1){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"3rd index value is "<<d1[3];
    return 0;
}