#include <iostream>
using namespace std;
class solution{
public:
    void triangle(int n ){
        for(int i =0;i<n;i++){
            for(int j=0;j<i+1;j++){
                cout << " *";
            }
            cout << endl;
        }
    }
};
int main(){
    solution star1;
    star1.triangle(5);
    return 0;
}