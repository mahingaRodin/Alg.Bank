#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

// method to display a linked list
void display(Node *head) {
    while(head != NULL) {
        cout << head->data<<" ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

//insertion of  new element in the linked list 
void insertion(Node*& head, int val) {
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}


int main() {
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();

    n1->data=10;
    n1->next=n2;
    n2->data = 20;
    n2->next=n3;
    n3->data = 30;
    n3->next = NULL;
    //displaying the linked list 
    display(n1);

    //implementation of insertion function
    insertion(n1, 5);
    display(n1);

    return 0;

}