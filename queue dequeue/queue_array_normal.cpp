#include <iostream>
using namespace std;

// Simple Linear Queue using Array
// NOTE: This is NOT circular queue.
class QueueArrayNormal {
private:
    int* arr;     // array to store queue elements
    int size;     // maximum capacity
    int front;    // index of current front element
    int rear;     // index where next element will be inserted

public:
    QueueArrayNormal(int n) {
        size = n;             // save capacity
        arr = new int[size];  // create array
        front = 0;            // queue starts empty
        rear = 0;             // queue starts empty
    }

    bool isEmpty() const {
        // If both are equal, no element is present
        return front == rear;
    }

    bool isFull() const {
        // In linear queue, rear reaching size means no more insertion
        return rear == size;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! enqueue fail\n";
            return;
        }

        arr[rear] = x;  // put element at rear position
        rear++;         // move rear for next insertion
        cout << x << " enqueue hua.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! dequeue fail\n";
            return -1;
        }

        int ans = arr[front]; // take front element
        front++;              // move front to next element

        // If queue becomes empty, reset both to start
        if (front == rear) {
            front = rear = 0;
        }

        return ans; // removed value
    }

    int getFront() const {
        if (isEmpty()) return -1;
        return arr[front]; // current front value
    }

    int getRear() const {
        if (isEmpty()) return -1;
        return arr[rear - 1]; // last inserted value
    }

    int count() const {
        return rear - front; // number of elements currently present
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue khaali hai.\n";
            return;
        }

        cout << "Queue (front -> rear): ";
        // Print all valid elements from front to rear-1
        for (int i = front; i < rear; i++) {
            cout << arr[i];
            if (i != rear - 1) cout << " ";
        }
        cout << "\n";
    }

    ~QueueArrayNormal() {
        delete[] arr;
    }
};

int main() {
    QueueArrayNormal q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "dequeue: " << q.dequeue() << "\n";
    q.display();

    cout << "Front: " << q.getFront() << "\n";
    cout << "Rear : " << q.getRear() << "\n";
    cout << "Count: " << q.count() << "\n";

    return 0;
}
