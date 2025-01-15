#include<iostream>
using namespace std;


//making it generic
template<typename T>
struct Node {
    T data;
    Node *next;
    Node(T d) {
        this->data = d;
        this->next = NULL;
    }
};


void display(Node<double>  *head) {
    while(head != NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<< endl;
}


int main() {
    Node<double> *n1 = new Node<double>(10);
    Node<double> *n2 = new Node<double> (20);
    Node<double>  *n3 = new Node<double> (30);
    Node<double>  *n4 = new Node<double> (40);
    Node<double>  n5 (50.56);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = &n5;
    display(n1);
    return 0;
}