#include <bits/stdc++.h>
using namespace std;

int countchar(char ch[]){
    int count=0;
    for(int i = 0; ch[i] != '\0'; i++){
        count++;
    }

    return count;

}
int main() {

    char ch[100];
    cout<<"Enter a string: ";
    cin>>ch;
    cout<<countchar(ch);
    return 0;
}