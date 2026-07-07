#include <iostream>
using namespace std;
//function to print an array
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";

    }
    cout<<"printing done "<<endl;
}

int main (){
    int marks[7]={2,3,4,5,6,7,8};
    cout<<marks[0]<<endl;
    cout<<marks[1]<<endl;
    cout<<marks[2]<<endl;

    //declare
    int number[15]={0};

    //accessing an array
    cout << "Value at 14 index " << number[14] << endl;

    //cout << "Value at 20 index " << number[20] << endl;

    //initialising an array 
    int second[3] = {5, 7, 11};

    //accesing an element
    cout << "Value at 2 index " << second[2] << endl;
    printarray(second, 3);
    printarray(marks, 7);
    //printarray(number, 15);  // Commented: would print 15 zeros causing huge output


    //making array of characters
    char ch[6] = {'s','s','f','d','f','g'};
    //it will not print the array by printarray function because it is a character array and printarray function is for integer arrays.
    // printarray(ch, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << ch[i] << " ";
    }
    cout << "printing done "<<endl;

    double first[4] = {2.3, 3.4, 5.6, 7.8};
    for (int i = 0; i < 4; i++)
    {
        cout << first[i] << " ";
    }
    cout << "printing done "<<endl;

    float arru[6];
    bool arrb[5];


    cout<<"Everything is fine "<<endl;
}