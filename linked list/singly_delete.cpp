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
}

void deleteHead(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
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
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

void deleteByValue(Node*& head, int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        deleteHead(head);
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
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

    cout << "Initial Singly List:\n";
    printList(head);

    deleteHead(head);
    cout << "After deleteHead:\n";
    printList(head);

    deleteTail(head);
    cout << "After deleteTail:\n";
    printList(head);

    deleteByValue(head, 30);
    cout << "After deleteByValue(30):\n";
    printList(head);

    freeList(head);
    return 0;
}
