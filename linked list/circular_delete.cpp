#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* getTail(Node* head) {
    if (head == nullptr) return nullptr;
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    return tail;
}

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

void appendForSetup(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        return;
    }
    Node* tail = getTail(head);
    tail->next = newNode;
    newNode->next = head;
}

void deleteHead(Node*& head) {
    if (head == nullptr) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* tail = getTail(head);
    Node* oldHead = head;
    head = head->next;
    tail->next = head;
    delete oldHead;
}

void deleteTail(Node*& head) {
    if (head == nullptr) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* prev = nullptr;
    Node* current = head;
    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    prev->next = head;
    delete current;
}

void deleteByValue(Node*& head, int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        deleteHead(head);
        return;
    }

    Node* prev = head;
    Node* current = head->next;
    while (current != head && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == head) return;

    prev->next = current->next;
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

    cout << "Initial Circular List:\n";
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
