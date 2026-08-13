#include <bits/stdc++.h>
using namespace std;

int main() {
    int num=10;
    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;

    int *p=&num; // pointer variable p stores the address of num
    cout << "Value of p (address of num): " << p << endl;
    cout << "Value pointed by p: " << *p << endl;

    double d=22.4;
    double *p2=&d; // pointer variable p2 stores the address of d
    cout << "Value of p2 (address of d): " << p2 << endl;
    cout << "Value pointed by p2: " << *p2 << endl;

    return 0;
}