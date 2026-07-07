#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(Node*& head, int position, int value) {
    if (position <= 1 || head == nullptr) {
        insertAtHead(head, value);
        return;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current->next != nullptr; ++i) {
        current = current->next;
    }

    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    insertAtHead(head, 11);
    insertAtHead(head, 7);
    insertAtTail(head, 66);
    insertAtPosition(head, 2, 9);

    cout << "Singly Linked List (Insertion Demo):\n";
    printList(head);

    freeList(head);
    return 0;
}
