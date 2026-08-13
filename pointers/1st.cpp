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

    cout<< "Size of pointer p: " << sizeof(p) << " bytes" << endl;
    cout<< "Size of pointer p2: " << sizeof(p2) << " bytes" << endl;
    cout<< "Size of pointer p3: " << sizeof(num) << " bytes" << endl;
    cout<< "Size of pointer p4: " << sizeof(d) << " bytes" << endl;

    return 0;
}