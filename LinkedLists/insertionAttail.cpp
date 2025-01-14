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
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* insertAtLast(Node* head, int data) {
    Node *n = new Node(data);
    if(head == NULL) {
        return n;
    }

    Node *tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = n;
    return head;
}


int main() {
    Node *n1 = NULL;
    Node *n2 = NULL;
    Node *n3 = NULL;

    n1 = new Node(10);
    n2 = new Node(20);
    n3 = new Node(30);
    n1->next = n2;
    n2->next = n3;

    insertAtLast(n1, 40);
    display(n1);
    return 0;
}