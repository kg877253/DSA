#include <iostream>
using namespace std;
class solution{
public:
    void box(int n){
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << " *";
            }
            cout << endl;
        }
    }
};
int main(){ 
    solution star;
    star.box(5);
    return 0;
}