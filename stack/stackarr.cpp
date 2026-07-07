#include <iostream>
using namespace std;

// Stack ki maximum capacity define kar rahe hain
#define MAX 100

class StackArray {
private:
    int arr[MAX];   // array jisme elements store honge
    int top;        // top ka index track karta hai (-1 matlab stack empty hai)

public:
    // Constructor — jab object banta hai, top ko -1 set karo (empty stack)
    StackArray() {
        top = -1;
    }

    // isEmpty — check karo stack khaali hai ya nahi
    bool isEmpty() {
        return top == -1;   // agar top = -1 toh kuch nahi hai stack mein
    }

    // isFull — check karo stack bhar gayi hai ya nahi
    bool isFull() {
        return top == MAX - 1;  // top ne last index pakad liya = full
    }

    // Push — element daalna stack mein (upar se)
    void push(int value) {
        if (isFull()) {
            // Agar stack full hai toh naya element nahi daal sakte — overflow!
            cout << "Stack Overflow! " << value << " nahi daal sakte.\n";
            return;
        }
        top++;              // pehle top badhao
        arr[top] = value;   // phir us position pe value daalo
        cout << value << " push kiya gaya.\n";
    }

    // Pop — sabse upar wala element nikalna
    int pop() {
        if (isEmpty()) {
            // Agar stack khaali hai toh kuch nikalna possible nahi — underflow!
            cout << "Stack Underflow! Stack khaali hai.\n";
            return -1;  // error indicate karne ke liye -1 return
        }
        int removed = arr[top]; // jo element nikalna hai usse save karo
        top--;                  // top ek neeche aa gaya
        return removed;         // nikala hua element return karo
    }

    // Peek — sirf top element dekho, nikalo mat
    int peek() {
        if (isEmpty()) {
            cout << "Stack khaali hai!\n";
            return -1;
        }
        return arr[top];    // top ka element return karo, top change nahi hoga
    }

    // Display — poori stack print karo (top se bottom tak)
    void display() {
        if (isEmpty()) {
            cout << "Stack khaali hai!\n";
            return;
        }
        cout << "Stack (Top se Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i != 0) cout << " -> ";
        }
        cout << "\n";
    }
};

// ===================== MAIN =====================
int main() {
    StackArray s;   // ek StackArray object banaya

    s.push(5);      // 5 daala
    s.push(3);      // 3 daala
    s.push(8);      // 8 daala
    s.push(1);      // 1 daala

    s.display();    // stack dikhao

    cout << "Top element: " << s.peek() << "\n";    // top dekho
    cout << "Pop kiya: " << s.pop() << "\n";        // top nikalo
    cout << "Pop kiya: " << s.pop() << "\n";        // phir nikalo

    s.display();    // ab kya bacha?

    return 0;
}
