#include<iostream>
using namespace std;


//making it generic
struct Node {
    int data;
    Node *next;
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

//adding at the beginning
Node *addAtHead(Node *head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
}

//add at tail
Node *addAtTail(Node *head, int data) {
    if(head == NULL) {
        Node *newNode = new Node(data);
        head = newNode;
        return head;
    }

    while(head->next != NULL) {
        head = head->next;
    }

    Node *newNode = new Node(data);
    head->next = newNode;
    return head;
}
void display(Node *head) {
    while(head != NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<< endl;
}

Node* userData() {
    int data;
    cout << "Add a number to the LL or -1 to exit" << endl;
    cin >> data;
    Node *head = NULL;
    while (data != -1) {
        Node *n = new Node(data);
        if(head == NULL) {
            head = n;
        } else {
            n->next = head;
            head = n;
        }
        cin >> data;
    }
    return head;
}


int main() {
    // Node *n1 = new Node(10);
    // Node *n2 = new Node(20);
    // Node *n3 = new Node(30);
    // Node *n4 = new Node(40);
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = NULL;
    // display(n1);

    Node *head = userData();
    display(head);
    return 0;
}