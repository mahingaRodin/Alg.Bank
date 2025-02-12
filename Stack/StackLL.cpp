#include<iostream>
using namespace std;

//implementing stack using linked list 

//initialize the linked list node 
struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
}

// initialize the stack class
class Stack {
    private:
        Node* top; // the top of the stack

        public:
            Stack() { top = NULL; }


            void push(int value) {
                Node *newNode = new Node(value);
                newNode->next = top;
                top = newNode;
                cout << value << " pushed to stack\n";
            } 

            void pop() {
                if(!top) {
                    cout<<"stack underflow!\n";
                    return;
                }
                cout << top->data << " popped from stack\n";
                Node* temp = top;
                top = top->next;
                delete temp;
            }

            int peek() {
                if(!top) {
                    cout << "Stack is empty!\n";
                    return -1;
                }
                return top->data;
            }

            bool isEmpty() {
                return top = NULL;
            }
};


int main() {
    Stack s;
    s.push(100);
    s.push(200);
    s.push(300);
    cout << "Top element: " << s.peek() << "\n";
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
