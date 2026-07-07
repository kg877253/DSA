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

void appendForSetup(Node*& head, int value) {
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
    appendForSetup(head, 10);
    appendForSetup(head, 20);
    appendForSetup(head, 30);
    appendForSetup(head, 40);

    cout << "Initial Doubly List:\n";
    printForward(head);

    deleteHead(head);
    cout << "After deleteHead:\n";
    printForward(head);

    deleteTail(head);
    cout << "After deleteTail:\n";
    printForward(head);

    deleteByValue(head, 30);
    cout << "After deleteByValue(30):\n";
    printForward(head);

    freeList(head);
    return 0;
}
