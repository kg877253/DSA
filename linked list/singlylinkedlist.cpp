#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

// Insert at beginning
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val); // 1) create new node
    newNode->next = head;          // 2) new node points to old head
    head = newNode;  
    cout << "Inserted " << val << " at the beginning.\n";
}

// Insert at end
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {         // empty list case
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;   // move to last node
    }
    current->next = newNode;       // link last node to new node
}

// Insert at 1-based position
void insertAtPosition(Node*& head, int pos, int val) {
    if (pos <= 0) return;

    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }

    Node* current = head;
    for (int i = 1; i < pos - 1 && current != nullptr; i++) {
        current = current->next;   // move to node before target position
    }

    if (current == nullptr) return; // invalid position

    Node* newNode = new Node(val);
    newNode->next = current->next;  // connect new node to next part
    current->next = newNode;        // connect previous part to new node
}

// Delete first node
void deleteHead(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;      // keep old head
    head = head->next;      // move head forward
    delete temp;            // free old head
}

// Delete last node
void deleteTail(Node*& head) {
    if (head == nullptr) return;           // empty list

    if (head->next == nullptr) {           // single node
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;           // stop at second-last
    }

    delete current->next;                  // delete last
    current->next = nullptr;               // second-last becomes last
}

// Delete first occurrence of value
void deleteByValue(Node*& head, int val) {
    if (head == nullptr) return;

    if (head->data == val) {               // value at head
        deleteHead(head);
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != val) {
        current = current->next;           // find node before target
    }

    if (current->next == nullptr) return;  // value not found

    Node* temp = current->next;            // target node
    current->next = temp->next;            // bypass target
    delete temp;                           // free memory
}

int main() {
    Node* head = nullptr;

    insertAtHead(head, 11);      // 11
    insertAtHead(head, 7);       // 7 -> 11
    insertAtTail(head, 66);      // 7 -> 11 -> 66
    insertAtPosition(head, 2, 9);// 7 -> 9 -> 11 -> 66
    printList(head);

    deleteHead(head);            // 9 -> 11 -> 66
    printList(head);

    deleteTail(head);            // 9 -> 11
    printList(head);

    deleteByValue(head, 9);      // 11
    printList(head);

    // cleanup remaining nodes
    while (head != nullptr) deleteHead(head);

    return 0;
}