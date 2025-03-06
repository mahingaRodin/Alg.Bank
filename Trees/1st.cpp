#include<iostream>
using namespace std;

//define a new node for the tree structure 
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

Node* createNode(int val) {
	return new Node(val);
}

void inorderTraversal(Node* root) {
	if(root != NULL) {
		inorderTraversal(root->left);
		cout<<root->data<<" ";
		inorderTraversal(root->right);
	}
}

int main() {
	Node *root = createNode(10);
	root->left = createNode(20);
	root->right = createNode(30);
	root->left->left = createNode(40);
	root->left->right = createNode(50);
	
	cout<<"Inorder traversal: ";
	inorderTraversal(root);
    return 0;
}
