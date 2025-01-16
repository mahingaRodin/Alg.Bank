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

void display(Node* tail) {
    if(tail == NULL) {
        cout<<"list is empty"<<endl;
        return;
    };

    Node *n = tail->next;
    
    do{
        cout << n->data << " ";
        n = n->next;
    } while (n != tail->next);

    cout<<"NULL"<<endl;
}

Node *addEnd(Node *tail, int data) {
    Node *n = new Node(data);
    if(tail == NULL) {
        n->next = n;
        tail = n;
    } else {
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
    return tail;
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
    n3->next = n1;

    display(n3);

    n3 = addEnd(n3, 40);
    cout << "new list: " << endl;
    display(n3);
    return 0;
}