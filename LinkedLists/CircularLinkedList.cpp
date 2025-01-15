#include<iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int data ) {
        this->data = data;
        this->next = NULL;
    }
};

void addFirst(Node*& tail , int data) {
    Node *newNode = new Node(data);
    if(tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}


void addLast(Node*&tail , int data) {
    addFirst(tail, data);
    tail = tail->next;
}

void display(Node* tail) {
    if(tail == NULL) {
        cout << "list is empty" << endl;
        return;
    }
    Node* temp = tail->next;
    do
        (
            cout << temp->data << " ";
            temp = temp->next;
            ) while(temp != tail->next);
    cout << endl;
}


int main() {

}