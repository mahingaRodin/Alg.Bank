#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


void display(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"NULL"<< endl;
}


int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node *n3 = new Node(30);
    n1->next = n2;
    n2->next = n3;
    display(n1);
    return 0;
}