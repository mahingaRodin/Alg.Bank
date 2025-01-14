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
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void addAtHead(Node **head, int val) {
    Node *n = new Node(val); // Create a new node
    n->next = *head;         // Point the new node to the current head
    *head = n;               // Update head to the new node
}

Node* addAtTail(Node* head, int val) {
    Node *n = new Node(val); // Create a new node
    if (head == NULL) {
        return n; // If the list is empty, return the new node as the head
    }
    Node *tail = head;
    while (tail->next != NULL) { // Traverse to the end of the list
        tail = tail->next;
    }
    tail->next = n; // Attach the new node at the tail
    return head;
}

int length(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    // Initialize nodes and create a linked list
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    n1->next = n2;
    n2->next = n3;
    head = n1; // Set the global head to the first node

    cout << "The current linked list: " << endl;
    display(head);

    // Add at the head
    addAtHead(&head, 4);
    cout << "The new linked list after adding at head: " << endl;
    display(head);

    // Add at the tail
    head = addAtTail(head, 40);
    cout << "The new linked list after adding at tail: " << endl;
    display(head);

    // Display the length of the list
    cout << "The length of the linked list is: " << length(head) << endl;

    return 0;
}
