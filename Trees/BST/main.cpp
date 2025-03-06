#include<iostream>
using namespace std;

//program to implement the Binary Search Tree

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//func to insert a new Node in the BST
Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

//func to search for a val inside the tree
bool search(Node* root, int val) {
    if(root == NULL) {
        return false;
    }
    
    if(val == root->data) {
        return true;
    }

    if(val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

//func for inorderTraversal 
void inorderTraversal(Node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    cout << "InorderTraversal: ";
    inorderTraversal(root);
    cout << endl;

    int searchVal = 100;
    if(search(root, searchVal)) {
        cout << "Val: " << searchVal << " found in the BST." << endl;
    } else {
        cout << "Val: " << searchVal << " not found in the BST." << endl;
    }

     int searchValu = 15;
    if(search(root, searchValu)) {
        cout << "Val: " << searchValu << " found in the BST." << endl;
    } else {
        cout << "Val: " << searchValu << " not found in the BST." << endl;
    }

    return 0;
}