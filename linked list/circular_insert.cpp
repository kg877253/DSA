#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << "\n";
}

void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->next = head;
}

void insertAtPosition(Node*& head, int position, int value) {
    if (position <= 1 || head == nullptr) {
        insertAtHead(head, value);
        return;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current->next != head; ++i) {
        current = current->next;
    }

    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
}

void deleteHeadForCleanup(Node*& head) {
    if (head == nullptr) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    Node* oldHead = head;
    head = head->next;
    tail->next = head;
    delete oldHead;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        deleteHeadForCleanup(head);
    }
}

int main() {
    Node* head = nullptr;

    insertAtHead(head, 20);
    insertAtHead(head, 10);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtPosition(head, 3, 25);

    cout << "Circular Linked List (Insertion Demo):\n";
    printList(head);

    freeList(head);
    return 0;
}
