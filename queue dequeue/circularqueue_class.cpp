#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int size;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = 0; // current front index
        rear = 0;  // next insertion index
        count = 0;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == size;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! " << value << " insert nahi ho sakta.\n";
            return;
        }

        arr[rear] = value;
        rear = (rear + 1) % size;
        count++;
        cout << value << " enqueue hua.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue khaali hai.\n";
            return -1;
        }

        int ans = arr[front];
        front = (front + 1) % size;
        count--;

        // Optional reset for cleaner state when empty
        if (count == 0) {
            front = rear = 0;
        }

        return ans;
    }

    int frontValue() const {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int rearValue() const {
        if (isEmpty()) return -1;
        int idx = (rear - 1 + size) % size;
        return arr[idx];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue khaali hai.\n";
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % size;
            cout << arr[index];
            if (i != count - 1) cout << " ";
        }
        cout << "\n";
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
    q.display();

    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // circular insertion
    q.display();

    cout << "Front value: " << q.frontValue() << "\n";
    cout << "Rear value : " << q.rearValue() << "\n";

    return 0;
}
