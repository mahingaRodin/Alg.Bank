#include<iostream>
#define SIZE 5 //size of the circular queue

using namespace std;

class Queue {
    private:
        int items[SIZE], front, rear;

        public:
        Queue() {
            front = -1;
            rear = -1;
        }
        //check if the queue is full
        bool isFull() {
            if(front == 0 && rear == SIZE - 1) {
                return true;
            }
            if(front == rear + 1) {
                return true;
            }
            return false;
        }

        bool isEmpty() {
            if(front == -1) {
                return true;
            } else {
                return false;
            }
        }

        //adding an element 
        void enQueue(int ele) {
            if(isFull()) {
                cout << "queue is full" << endl;
            } else {
                if(front == -1)
                    front = 0;
                rear = (rear + 1) % SIZE;
                items[rear] = ele;
                cout << endl;
                cout << "Inserted " << ele << endl;
            }
        }

        int deQueue() {
            int ele;
            if(isEmpty()) {
                cout << "queue is empty" << endl;
                return (-1);
            } else {
                ele = items[front];
                if(front == rear) {
                    front = -1;
                    rear = -1;
                }
                //q has only one element
                //so we reset the queue after deleting it 
                else {
                    front = (front + 1) % SIZE;
                }
                return (ele);
            }
        }


        void display() {
            //function to display all elements
            int i;
            if(isEmpty()) {
                cout << "Empty Queue" << endl;
            } else {
                cout << "Front-> " << front;
                cout << endl;
                cout << "Items-> ";
                for(i = front; i != rear; i = (i + 1) % SIZE) {
                    cout << items[i] << " ";
                    cout << items[i] << " ";
                    cout << endl
                         << "Rear -> " << rear;
                }
            }
        }
};


int main() {
    Queue q;

    q.deQueue();
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    //fails to enque cz front == 0 && rear == SIZE - 1
    q.enQueue(6);

    q.display();
    int ele = q.deQueue();
    if(ele != -1) {
        cout << endl
             << "Delete element is: " << elem;
    }
    q.display();
    q.enQueue(7);
    q.display();
    q.enQueue(8);
    return 0;
}
