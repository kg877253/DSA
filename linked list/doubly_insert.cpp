#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void printForward(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
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
    newNode->prev = current;
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

    if (current->next == nullptr) {
        insertAtTail(head, value);
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
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

    insertAtHead(head, 20);
    insertAtHead(head, 10);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtPosition(head, 3, 25);

    cout << "Doubly Linked List (Insertion Demo):\n";
    printForward(head);

    freeList(head);
    return 0;
}
