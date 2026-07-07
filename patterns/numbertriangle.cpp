#include <iostream>
using namespace std;
class Solution {
public:
    void numbertriangle(int n) {
        for(int i =0;i<n;i++){
            for(int j=1;j<=i+1;j++){
                cout<<j;
            }
            cout<<endl;
        }

    }
};
int main(){
    Solution star1;
    star1.numbertriangle(5);
    return 0;
}