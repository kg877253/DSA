#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Returns priority of operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Converts infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix;

    for (char ch : infix) {
        // Ignore spaces
        if (ch == ' ') continue;

        // If operand (a-z, A-Z, 0-9), add directly to result
        if (isalnum(static_cast<unsigned char>(ch))) {
            postfix += ch;
        }
        // Push opening bracket
        else if (ch == '(') {
            st.push(ch);
        }
        // Pop until opening bracket for ')'
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop(); // remove '('
            }
        }
        // Operator case
        else {
            while (!st.empty() && st.top() != '(' &&
                   precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << "\n";

    return 0;
}
