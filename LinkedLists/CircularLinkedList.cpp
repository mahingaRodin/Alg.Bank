#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtBeginning(Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void insertAtEnd(Node*& tail, int data) {
    insertAtBeginning(tail, data);
    tail = tail->next;
}

void deleteNode(Node*& tail, int key) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (tail->next == tail && tail->data == key) {
        delete tail;
        tail = NULL;
        return;
    }

    Node* prev = tail;
    Node* curr = tail->next;

    do {
        if (curr->data == key) {
            prev->next = curr->next;
            if (curr == tail) {
                tail = prev;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    cout << "Node with value " << key << " not found!" << endl;
}

void display(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main() {
    Node* tail = NULL;

    // Insert nodes
    insertAtBeginning(tail, 10);
    insertAtEnd(tail, 20);
    insertAtEnd(tail, 30);
    insertAtEnd(tail, 40);

    // Display the list
    cout << "Circular Linked List: ";
    display(tail);

    // Delete a node
    deleteNode(tail, 20);
    cout << "After deleting 20: ";
    display(tail);

    // Delete another node
    deleteNode(tail, 10);
    cout << "After deleting 10: ";
    display(tail);

    return 0;
}
