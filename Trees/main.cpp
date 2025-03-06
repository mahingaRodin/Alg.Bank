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

int main() {
	Node *root = createNode(10);
	root->left = createNode(20);
	root->right = createNode(30);
	root->left->left = createNode(40);
	root->right->right = createNode(50);
	
	    cout << "Elements in the tree: ";
    cout << root->data << " ";                  
    cout << root->left->data << " ";              
    cout << root->right->data << " ";              
    cout << root->left->left->data << " ";         
    cout << root->left->right->data << " "; 
    cout<<endl;
    
    return 0;
}
