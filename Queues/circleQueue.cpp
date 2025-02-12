#include<iostream>
using namespace std;

//structure for the circular queue
struct Node {
    int data;
    Node* next;
};

class CircularQueue {
    private:
        Node *rear;

        public:
        CircularQueue() { rear = NULL; }

        void enqueue(int value) {
            Node *newNode = new Node{value, NULL};
            if(!rear) {
                rear = newNode;
                rear->next = rear;
            } else {
                newNode->next = rear->next;
                rear->next = newNode;
                rear = newNode;
            }
        }


        void dequeue() {
            if(!rear) {
                cout << "Queue is empty!\n";
                return;
            }
            Node *temp = rear->next;
            if(rear == rear->next) {
                rear = NULL;
            } else {
                rear->next = temp->next;
            }
            delete temp;
        }

        void display() {
            if(!rear) {
                cout << "queue is empty!\n";
                return;
            }
            Node* temp = rear->next;
            do{
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != rear->next);
            cout << "\n";
        }
};


int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();
    cq.dequeue();
    cq.display();
    return 0;
}