#include<iostream>
using namespace std;
struct node{
int data;
node*next;
};
int main(){
node*n1=new node();
n1-> data=10;

node*n2=new node();
n2->data=20;

node*n3=new node();
n3->data=30;

node*n4=new node ();
n4->data=40;

n1->next=n2;
n2->next=n3;
n3->next=n4;
n4->next=NULL;

node*temp=n1;
while (temp!=NULL){
cout << temp->data << " ";
temp=temp->next;
}
cout<<"NULL";
return 0;
}



    //cout << "Hello World!" << endl;