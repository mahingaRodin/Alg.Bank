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

//insertion at head(first)
void addFirst(Node*& head, int data) {
    Node* n = new Node(data);
    n->next = head; // link new node to current head
    if(head != NULL) {
        head->previous = n;// update the current head's previous pointer
    }
    head = n; // update the head to the new node
}

//insertion at end 
void addEnd(Node*& head , int data) {
    Node* n1 = new Node(data);
    if(head == NULL) {
        head = n1;
        return;
    }
    Node *n = head;
    while(n->next != NULL) {
        n = n->next;
    }
    n->next = n1;
    n1->previous = n;
}

//inserting after a given node
void insertAfter(Node* giveNode , int data) {
    if(giveNode == NULL) {
        cout << "given node can't be NULL";
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = giveNode->next;
    newNode->previous = giveNode;
    if(giveNode->next != NULL) {
        giveNode->next->previous = newNode;
    }
    giveNode->next = newNode;
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

    addFirst(n1, 5);
    cout << "new list: " << endl;
    display(n1);
    addEnd(n1, 40);
    cout << "new list: " << endl;
    display(n1);
    insertAfter(n2, 33);
    cout << "new list: " << endl;
    display(n1);
    return 0;
    }