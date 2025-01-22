#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int da) {
        data = da;
        next = NULL;
    }
};

Node* mid(Node* head) {
    Node* slow = head;
    Node *fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *a, Node *b) {
    //base case
    if(a==NULL)
        return b;
        if(b==NULL)
            return a;

            //recursive case
        Node *c;

        if(a->data < b->data) {
            c = a;
            c->next = merge(a->next, b);
        } else {
            c = b;
            c->next = merge(a, b->next);
        }
        return c;
}


Node* mergeSort(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node *middle = mid(head);
    Node *b = middle->next;
    middle->next = NULL;

    Node *a = mergeSort(head);
    b = mergeSort(b);

    return merge(a, b);
}
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}


int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(100);
    Node* n3 = new Node(3);
    Node* n4 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    
    display(n1);
    n1 = mergeSort(n1);
    display(n1);

    return 0;
}
