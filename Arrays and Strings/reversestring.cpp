#include <iostream>
using namespace std;

void reverse(char ch[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(ch[s++],ch[e--]);
    }
}
int main() {
    char chr[100];
    cout<<"Enter a string: ";
    cin>>chr;
    int len = 0;
    while(chr[len] != '\0') {
        len++;
    }
    reverse(chr,len);
    cout<<"Reversed string: "<<chr<<endl;
    return 0;
}