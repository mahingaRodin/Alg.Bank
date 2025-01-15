#include<iostream>
using namespace std;

struct Node {
    Node *previous;
    int data;
    Node *next;
    Node(int data) {
        this->previous = NULL;
        this->data = data;
        this->next = NULL;
    }
};

void display(Node* head) {
    Node* n = head;
    while(n!= NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << "NULL" << endl;
}


int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    n1->next = n2;
    n2->previous = n1;
    n2->next = n3;
    n3->previous = n2;

    display(n1);
    return 0;
    }