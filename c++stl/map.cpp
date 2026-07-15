#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // map<string,int> m;

    // m["headphone"]=100;
    // m["mobile"]=300;
    // m["laptop"]=400;
    // m["camera"]=500;
    // m.insert({"telephone",600});
    // m.emplace("watch",700);

    // m.erase("mobile"); //erase the key mobile from the map

    multimap<string,int> m1;
    m1.insert({"headphone",100});
    m1.insert({"mobile",300});
    m1.insert({"laptop",400});
    m1.emplace("camera",500);
    m1.emplace("camera",600); // This will create another entry with the same key
    m1.emplace("camera",600);

    // m1.erase("camera"); //erase the key mobile from the map jitni bhi honge camera key wali entries unko erase kar dega
    m1.erase(m1.find("camera")); //erase the key mobile from the map par sirf 1 hi entry ko erase karega

    // unordered_map<string,int> m;
    // m.emplace("headphone",100);
    // m.emplace("mobile",300);
    // m.emplace("laptop",400);
    // m.emplace("phone",600);
    // m.emplace("camera",500);

    //for (map)order sorted in ascending order of key (a,b,c...like that).
    //for (unordered_map)order is not sorted, it is random order.
    for(auto p:m1){
        cout<<p.first<<" "<<p.second<<endl;
    }
    
    return 0;
}