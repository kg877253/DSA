#include <iostream>
using namespace std;

struct Node {
    int data;       // value stored in node
    Node* left;     // pointer to left child
    Node* right;    // pointer to right child

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Build tree recursively
// Input rule: enter -1 means "no node"
Node* buildTree(Node* root) {
    cout << "Enter the data (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    root = new Node(data);

    cout << "Enter data for inserting in left of " << data << "\n";
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << "\n";
    root->right = buildTree(root->right);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    cout << "Enter nodes in preorder form (-1 for NULL):\n";
    cout << "Example: 1 2 -1 -1 3 -1 -1\n";

    Node* root = nullptr;
    root = buildTree(root);

    cout << "Inorder  : ";
    inorder(root);
    cout << "\n";

    freeTree(root);
    return 0;
}
