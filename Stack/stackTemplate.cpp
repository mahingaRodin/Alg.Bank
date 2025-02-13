#include<iostream>
using namespace std;

template <typename T>
class Node {
    T data;
    Node<T> *next;
    public:
    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;
    public:
    Stack() {
        head = NULL;
        size = 0;
    }

    bool isEmpty() {

    }

    void push(T ele) {
        Node *newNode = new Node(ele);
        newNode->next = head;
        head = newNode;
        cout << ele << " pushed" << endl;
    } 

    void pop() {
        if(!head) {
            cout << "stack underflow!" << endl;
        }
        cout<<head->data<<" popped from stack"<<endl;
        Node *temp = head;
        head = head->next;
        delete temp;
    } 

    T top() {
        if(!head) {
            cout << "Stack is empty!" << endl;
    
            return -1;
                }
                return head->data;
    }
};

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push
    return 0;
}