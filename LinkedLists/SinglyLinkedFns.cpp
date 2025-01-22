#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

// method to display a linked list
void display(Node *head) {
    while(head != NULL) {
        cout << head->data<<" ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

//insertion of  new element in the linked list 
void insertion(Node*& head, int val) {
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

//searching an element in the linked list 
int search(Node* head, int target) {
    Node *current = head;
    int position = 1;

    while(current != NULL) {
        if(current->data == target) {
            return position;
        };
       current = current->next;
     position++;
    }

    return -1;// if the element isnot found
}

//method to delete the first element
Node *deleteHead(Node *head) {
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

//delete end
Node *deleteEnd(Node* head) {
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node *temp = head;
    while(temp->next->next != NULL) {
        delete (temp->next);
        temp->next = NULL;
        }
        return head;
}

int main() {
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();

    n1->data=10;
    n1->next=n2;
    n2->data = 20;
    n2->next=n3;
    n3->data = 30;
    n3->next = NULL;
    //displaying the linked list 
    display(n1);

    //implementation of insertion function
    insertion(n1, 5);
    display(n1);

    //implementation of searching function
    if(search(n1, 30) != -1) {
        cout << "Element found at position: " << search(n1, 30) << endl;
    } else {
        cout << "Elemenet not found" << endl;
    }

    Node* head = deleteEnd(n1);
    display(head);

    return 0;

}