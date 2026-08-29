#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
    int n[10]={1,2,3,64,5,6,7,8,9,10};
    
    int *p=n;
    cout<<&n<<" "<<n<<endl;
    cout<<*n<<endl;
    cout<<&n[6]<<" "<<n[6]<<endl;
    cout<<"--"<<*(p+3)<<endl;
    
    int i =4;
    //all same bcs of pointer arithmetic= *(n+i) = n[i] = i[n]
    cout<<i[n]<<" "<<*(n+i)<<" "<<n[i]<<endl;
    */

    int temp[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<sizeof(temp)<<" "<<sizeof(*temp)<<" "<<sizeof(&temp)<<endl;

    int *ptr=&temp[0];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(ptr)<<endl;
    
    return 0;
}