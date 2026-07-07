#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

public:
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        // Move value upward while parent is smaller
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] >= heap[index]) break;

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    int deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        int index = 0;
        int n = heap.size();

        // Move root downward to correct position
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < n && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < n && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest == index) break;

            swap(heap[index], heap[largest]);
            index = largest;
        }

        return root;
    }

    void display() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << "\n";
    }
};

int main() {
    MaxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(20);
    h.insert(40);
    h.insert(60);
    h.insert(80);

    cout << "Max Heap: ";
    h.display();

    cout << "Deleted root: " << h.deleteRoot() << "\n";

    cout << "After deletion: ";
    h.display();

    return 0;
}
