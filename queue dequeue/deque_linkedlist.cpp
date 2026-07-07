#include <iostream>
using namespace std;

struct Node {
    int data;      // Value stored in node
    Node* prev;    // Pointer to previous node
    Node* next;    // Pointer to next node

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DequeLinkedList {
private:
    Node* frontNode;   // Points to front of deque
    Node* rearNode;    // Points to rear of deque
    int count;         // Number of elements

public:
    DequeLinkedList() {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    bool isEmpty() const {
        return frontNode == nullptr;
    }

    int size() const {
        return count;
    }

    // Insert at front
    void pushFront(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            newNode->next = frontNode;
            frontNode->prev = newNode;
            frontNode = newNode;
        }

        count++;
        cout << value << " pushFront hua.\n";
    }

    // Insert at rear
    void pushRear(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            newNode->prev = rearNode;
            rearNode = newNode;
        }

        count++;
        cout << value << " pushRear hua.\n";
    }

    // Remove from front
    int popFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! Empty hai.\n";
            return -1;
        }

        Node* temp = frontNode;
        int removed = temp->data;

        if (frontNode == rearNode) {
            frontNode = rearNode = nullptr;
        } else {
            frontNode = frontNode->next;
            frontNode->prev = nullptr;
        }

        delete temp;
        count--;
        return removed;
    }

    // Remove from rear
    int popRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! Empty hai.\n";
            return -1;
        }

        Node* temp = rearNode;
        int removed = temp->data;

        if (frontNode == rearNode) {
            frontNode = rearNode = nullptr;
        } else {
            rearNode = rearNode->prev;
            rearNode->next = nullptr;
        }

        delete temp;
        count--;
        return removed;
    }

    int getFront() const {
        if (isEmpty()) return -1;
        return frontNode->data;
    }

    int getRear() const {
        if (isEmpty()) return -1;
        return rearNode->data;
    }

    void displayForward() const {
        if (isEmpty()) {
            cout << "Deque empty hai.\n";
            return;
        }

        cout << "Deque (front -> rear): ";
        Node* current = frontNode;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " ";
            current = current->next;
        }
        cout << "\n";
    }

    void displayBackward() const {
        if (isEmpty()) {
            cout << "Deque empty hai.\n";
            return;
        }

        cout << "Deque (rear -> front): ";
        Node* current = rearNode;
        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr) cout << " ";
            current = current->prev;
        }
        cout << "\n";
    }

    ~DequeLinkedList() {
        while (!isEmpty()) {
            popFront();
        }
    }
};

int main() {
    DequeLinkedList dq;

    dq.pushRear(20);
    dq.pushRear(30);
    dq.pushFront(10);
    dq.pushRear(40);

    dq.displayForward();
    dq.displayBackward();

    cout << "Front: " << dq.getFront() << "\n";
    cout << "Rear : " << dq.getRear() << "\n";

    cout << "popFront: " << dq.popFront() << "\n";
    cout << "popRear : " << dq.popRear() << "\n";

    dq.displayForward();
    cout << "Size: " << dq.size() << "\n";

    return 0;
}
