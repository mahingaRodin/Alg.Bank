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
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<< endl;
}


int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    display(n3);
    return 0;
}