#include <iostream>
using namespace std;

class QueueArray {
private:
    int* arr;          // Dynamic array to store queue elements
    int capacity;      // Maximum number of elements queue can hold
    int frontIndex;    // Points to current front element
    int rearIndex;     // Points to current rear element
    int count;         // Current number of elements in queue

public:
    QueueArray(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;      // Start front at 0
        rearIndex = -1;      // Rear is -1 before first insertion
        count = 0;           // Queue initially empty
    }

    bool isEmpty() const {
        return count == 0;   // Empty when element count is 0
    }

    bool isFull() const {
        return count == capacity; // Full when count reaches capacity
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! " << value << " insert nahi ho sakta.\n";
            return;
        }

        // Circular move of rear: if rear reaches end, it wraps to 0
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;
        cout << value << " enqueue hua.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue khaali hai.\n";
            return -1;
        }

        int removed = arr[frontIndex]; // Save front value to return it

        // Circular move of front
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return removed;
    }

    int front() const {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    int rear() const {
        if (isEmpty()) return -1;
        return arr[rearIndex];
    }

    int size() const {
        return count;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue khaali hai.\n";
            return;
        }

        cout << "Queue (front -> rear): ";
        for (int i = 0; i < count; i++) {
            int index = (frontIndex + i) % capacity; // Circular access
            cout << arr[index];
            if (i != count - 1) cout << " ";
        }
        cout << "\n";
    }

    ~QueueArray() {
        delete[] arr;
    }
};

int main() {
    QueueArray q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front: " << q.front() << "\n";
    cout << "Rear : " << q.rear() << "\n";

    cout << "Dequeued: " << q.dequeue() << "\n";
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    cout << "Size: " << q.size() << "\n";
    return 0;
}
