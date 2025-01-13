#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

void display(Node *n) {
    while(n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main() {
    //statically
    Node n1(1);
    Node n2(2);

    //n1.next should be the address of n2 inorder to create a linked list
    n1.next = &n2;
    cout << n1.data << " " << n2.data << endl;
    //head is not a node but it is a pointer to the first node
    Node *head = &n1;
    //dynamically
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    //connect the second node and the third node
    n2.next = n3;
    //link the third node to the fourth node
    n3->next = n4;
    display(head);
    return 0;
}