#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // 1) Create three node pointers.
    Node* head;
    Node* second;
    Node* third;

    // 2) Allocate memory for each node in the heap.
    head = new Node();
    second = new Node();
    third = new Node();

    // 3) Fill first node and connect it to second.
    head->data = 7;
    head->next = second;

    // 4) Fill second node and connect it to third.
    second->data = 11;
    second->next = third;

    // 5) Fill third node and mark end of list.
    third->data = 66;
    third->next = nullptr;

    // 6) Traverse and print linked list values.
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // 7) Free heap memory.
    delete head;
    delete second;
    delete third;

    return 0;
}
