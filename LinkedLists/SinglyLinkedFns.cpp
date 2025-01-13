#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

// method to display a linked list
int display(Node *head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
    }
}