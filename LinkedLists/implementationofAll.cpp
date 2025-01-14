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

Node *head = NULL;

void display(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void addAtHead(Node **head, int val) {
    Node *n = new Node(val);
    n->data = val;
    n->next = *head;
    *head = n;
}


Node* addAtTail(Node* head, int val) {
    Node *n = new Node(val);
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

int length(Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
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
    head = n1;

    cout << "The current linked list: " << endl;
    display(n1);

    addAtHead(&head, 4);
    cout << "The new linked list: " << endl;
    display(n1);

    addAtTail(head, 40);
    cout << "The new linked list: " << endl;
    display(n1);

    cout << endl;
    cout<<"The lenght of the linked list is: " << length(head) << endl;
    return 0;
}