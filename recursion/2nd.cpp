#include <bits/stdc++.h>
using namespace std;

//by recursive method
int fib(int n ) {
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1)+fib(n-2);
}

//by iterative method
int fib2(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++) {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main() {
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    cout<<fib2(n)<<endl;
    return 0;
}