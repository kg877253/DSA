#include <iostream>
using namespace std;

// Double Ended Queue (Deque) using Array
// We can insert/delete from BOTH front and rear.
class Deque {
private:
    int* arr;      // array to store elements
    int size;      // total capacity
    int front;     // index of front element
    int rear;      // index of rear element

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = -1;  // empty deque
        rear = -1;   // empty deque
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        // Full when:
        // 1) front at 0 and rear at end
        // 2) or front is just next to rear in circular way
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    void pushFront(int x) {
        if (isFull()) {
            cout << "Overflow! pushFront fail\n";
            return;
        }

        if (isEmpty()) {
            // first element
            front = rear = 0;
        } else if (front == 0) {
            // wrap front to last index
            front = size - 1;
        } else {
            front--;
        }

        arr[front] = x;
        cout << x << " inserted at front.\n";
    }

    void pushRear(int x) {
        if (isFull()) {
            cout << "Overflow! pushRear fail\n";
            return;
        }

        if (isEmpty()) {
            // first element
            front = rear = 0;
        } else if (rear == size - 1) {
            // wrap rear to index 0
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        cout << x << " inserted at rear.\n";
    }

    int popFront() {
        if (isEmpty()) {
            cout << "Underflow! popFront fail\n";
            return -1;
        }

        int ans = arr[front];

        if (front == rear) {
            // single element case
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0; // wrap
        } else {
            front++;
        }

        return ans;
    }

    int popRear() {
        if (isEmpty()) {
            cout << "Underflow! popRear fail\n";
            return -1;
        }

        int ans = arr[rear];

        if (front == rear) {
            // single element case
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1; // wrap
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
            cout << "Deque is empty.\n";
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

    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque dq(5);

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
