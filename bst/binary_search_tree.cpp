#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree rule:
// smaller value goes to left, bigger value goes to right.
Node* insertIntoBST(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertIntoBST(root->left, value);
    } else {
        root->right = insertIntoBST(root->right, value);
    }

    return root;
}

Node* buildBST() {
    Node* root = nullptr;
    int value;

    cout << "Enter data for BST (-1 to stop): ";
    cin >> value;

    while (value != -1) {
        root = insertIntoBST(root, value);
        cout << "Enter next data (-1 to stop): ";
        cin >> value;
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool searchBST(Node* root, int key) {
    if (root == nullptr) return false;

    if (root->data == key) return true;

    if (key < root->data) {
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    cout << "Binary Search Tree Creation\n";
    cout << "Example input: 50 30 70 20 40 60 80 -1\n";

    Node* root = buildBST();

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << "\n";

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (searchBST(root, key)) {
        cout << key << " found in BST.\n";
    } else {
        cout << key << " not found in BST.\n";
    }

    freeTree(root);
    return 0;
}
