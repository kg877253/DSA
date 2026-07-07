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

void deleteHead(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteTail(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->prev->next = nullptr;
    delete current;
}

void deleteByValue(Node*& head, int value) {
    if (head == nullptr) return;

    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current == nullptr) return;
    if (current == head) {
        deleteHead(head);
        return;
    }
    if (current->next == nullptr) {
        deleteTail(head);
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        deleteHead(head);
    }
}

int main() {
    Node* head = nullptr;

    insertAtHead(head, 20);
    insertAtHead(head, 10);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtPosition(head, 3, 25);

    cout << "Doubly List after insertions:\n";
    printForward(head);

    deleteHead(head);
    deleteTail(head);
    deleteByValue(head, 25);

    cout << "Doubly List after deletions:\n";
    printForward(head);

    freeList(head);
    return 0;
}
