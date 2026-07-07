#include <iostream>
using namespace std;

class DequeArray {
private:
    int* arr;
    int size;
    int front;
    int rear;

public:
    DequeArray(int n) {
        size = n;
        arr = new int[size];
        front = -1; // empty deque
        rear = -1;  // empty deque
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    void pushFront(int x) {
        if (isFull()) {
            cout << "Deque Overflow! pushFront fail\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }

        arr[front] = x;
        cout << x << " pushFront hua.\n";
    }

    void pushRear(int x) {
        if (isFull()) {
            cout << "Deque Overflow! pushRear fail\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        cout << x << " pushRear hua.\n";
    }

    int popFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! popFront fail\n";
            return -1;
        }

        int ans = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }

        return ans;
    }

    int popRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! popRear fail\n";
            return -1;
        }

        int ans = arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }

        return ans;
    }

    int getFront() const {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() const {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Deque empty hai.\n";
            return;
        }

        cout << "Deque (front -> rear): ";
        int i = front;
        while (true) {
            cout << arr[i];
            if (i == rear) break;
            cout << " ";
            i = (i + 1) % size;
        }
        cout << "\n";
    }

    ~DequeArray() {
        delete[] arr;
    }
};

int main() {
    DequeArray dq(5);

    dq.pushRear(20);
    dq.pushRear(30);
    dq.pushFront(10);
    dq.pushRear(40);
    dq.display();

    cout << "Front: " << dq.getFront() << "\n";
    cout << "Rear : " << dq.getRear() << "\n";

    cout << "popFront: " << dq.popFront() << "\n";
    cout << "popRear : " << dq.popRear() << "\n";
    dq.display();

    return 0;
}
