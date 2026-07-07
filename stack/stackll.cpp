#include <iostream>
using namespace std;

// Node structure — Linked List ka building block
struct Node {
    int data;       // actual value store hogi yahan
    Node* next;     // agla node ka address (pointer)
};

class StackLinkedList {
private:
    Node* top;      // top pointer — hamesha stack ke sabse upar wale node ko point karta hai

public:
    // Constructor — shuru mein top NULL hai (stack khaali)
    StackLinkedList() {
        top = NULL;
    }

    // isEmpty — agar top NULL hai toh stack khaali hai
    bool isEmpty() {
        return top == NULL;
    }

    // Push — naya node banao aur stack ke upar chipka do
    void push(int value) {
        Node* newNode = new Node();  // heap pe naya node banaya (dynamic allocation)
        newNode->data = value;       // node mein value daali
        newNode->next = top;         // naye node ka next pointer purane top ko point karega
        top = newNode;               // ab top naye node ko point karega
        cout << value << " push kiya gaya.\n";
    }

    // Pop — top node ko hatao aur uski value return karo
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack khaali hai.\n";
            return -1;
        }
        Node* temp = top;       // top node ko temp mein save karo (baad mein delete karenge)
        int removed = top->data; // value nikal ke rakh lo
        top = top->next;         // top ek neeche wale node pe aa gaya
        delete temp;             // purana top node ki memory free karo (memory leak rok rahe hain)
        return removed;          // nikali hui value return karo
    }

    // Peek — sirf top ka data dekho
    int peek() {
        if (isEmpty()) {
            cout << "Stack khaali hai!\n";
            return -1;
        }
        return top->data;   // top node ka data return karo
    }

    // Display — top se neeche tak traverse karo
    void display() {
        if (isEmpty()) {
            cout << "Stack khaali hai!\n";
            return;
        }
        Node* curr = top;   // ek temporary pointer banaya jo traverse karega
        cout << "Stack (Top se Bottom): ";
        while (curr != NULL) {          // jab tak nodes hain, chalte raho
            cout << curr->data;
            if (curr->next != NULL) cout << " -> ";
            curr = curr->next;          // agle node pe jao
        }
        cout << "\n";
    }

    // Destructor — object destroy hone pe saari memory free karo
    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();  // ek ek karke sab pop karo
        }
    }
};

// ===================== MAIN =====================
int main() {
    StackLinkedList s;  // linked list stack banaya

    s.push(5);   // 5 daala
    s.push(3);   // 3 daala
    s.push(8);   // 8 daala
    s.push(1);   // 1 daala

    s.display(); // stack print karo

    cout << "Top element: " << s.peek() << "\n";
    cout << "Pop kiya: " << s.pop() << "\n";
    cout << "Pop kiya: " << s.pop() << "\n";

    s.display(); // ab kya bacha?

    return 0;
}
