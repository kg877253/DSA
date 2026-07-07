#include <iostream>
using namespace std;

struct Node {
    int data;                       // value stored in the node
    Node* next;                     // pointer to next node
    Node(int value) : data(value), next(nullptr) {} // constructor initializes data and next
};

void printList(Node* head) {
    if (head == nullptr) {          // empty list check
        cout << "List is empty\n";
        return;
    }
    Node* current = head;           // start traversal from head
    do {
        cout << current->data << " "; // print current node data
        current = current->next;      // move to next node
    } while (current != head);        // stop when we come back to head (circular condition)
    cout << "\n";
}

Node* getTail(Node* head) {
    if (head == nullptr) return nullptr; // no tail in empty list
    Node* tail = head;                   // start from head
    while (tail->next != head) {
        tail = tail->next;               // move until last node (whose next points to head)
    }
    return tail;                         // return last node
}

void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value); // create new node
    if (head == nullptr) {
        head = newNode;              // new node becomes head
        head->next = head;           // single node points to itself (circular)
        return;
    }
    Node* tail = getTail(head);      // find current tail
    newNode->next = head;            // new node points to old head
    tail->next = newNode;            // tail now points to new head node
    head = newNode;                  // update head to new node
}

void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value); // create new node
    if (head == nullptr) {
        head = newNode;              // new node becomes head
        head->next = head;           // single node circular link
        return;
    }
    Node* tail = getTail(head);      // find old tail
    tail->next = newNode;            // old tail points to new node
    newNode->next = head;            // new tail points back to head
}

void insertAtPosition(Node*& head, int position, int value) {
    if (position <= 1 || head == nullptr) { // position 1 or empty list => head insertion
        insertAtHead(head, value);          // reuse existing function
        return;
    }
    Node* current = head; // traverse to node before target position
    for (int i = 1; i < position - 1 && current->next != head; i++) {
        current = current->next;
    }
    Node* newNode = new Node(value); // create new node
    newNode->next = current->next;   // link new node to next part
    current->next = newNode;         // link previous part to new node
}

void deleteHead(Node*& head) {
    if (head == nullptr) return; // nothing to delete
    if (head->next == head) {
        delete head;             // delete the only node
        head = nullptr;          // list becomes empty
        return;
    }
    Node* tail = getTail(head);  // find tail to repair circular link
    Node* oldHead = head;        // store current head for deletion
    head = head->next;           // move head to next node
    tail->next = head;           // tail should point to new head
    delete oldHead;              // free old head memory
}

void deleteTail(Node*& head) {
    if (head == nullptr) return; // empty list
    if (head->next == head) {
        delete head;             // delete the only node
        head = nullptr;          // list becomes empty
        return;
    }
    Node* prev = nullptr;        // will track node before tail
    Node* current = head;        // traversal pointer
    while (current->next != head) {
        prev = current;          // move prev
        current = current->next; // move current
    }
    prev->next = head;           // second-last node becomes new tail
    delete current;              // delete old tail
}

void deleteByValue(Node*& head, int value) {
    if (head == nullptr) return; // empty list
    if (head->data == value) {
        deleteHead(head);        // if head matches, reuse deleteHead
        return;
    }
    Node* prev = head;           // previous node pointer
    Node* current = head->next;  // start from second node
    while (current != head && current->data != value) {
        prev = current;          // move prev forward
        current = current->next; // move current forward
    }
    if (current == head) return; // value not found
    prev->next = current->next;  // bypass matched node
    delete current;              // free removed node
}

void freeList(Node*& head) {
    while (head != nullptr) {
        deleteHead(head); // repeatedly delete head until list is empty
    }
}

void runCircularListDemo() {
    Node* head = nullptr; // initially empty circular list
    insertAtHead(head, 20);        // list: 20
    insertAtHead(head, 10);        // list: 10 20
    insertAtTail(head, 30);        // list: 10 20 30
    insertAtTail(head, 40);        // list: 10 20 30 40
    insertAtPosition(head, 3, 25); // list: 10 20 25 30 40
    cout << "After insertions: ";
    printList(head);
    deleteHead(head);              // remove 10
    cout << "After delete head: ";
    printList(head);
    deleteTail(head);              // remove 40
    cout << "After delete tail: ";
    printList(head);
    deleteByValue(head, 25);       // remove 25
    cout << "After delete value 25: ";
    printList(head);
    freeList(head); // cleanup all remaining nodes
}

int main() {
    runCircularListDemo(); // single clear function call from main
    return 0;
}
