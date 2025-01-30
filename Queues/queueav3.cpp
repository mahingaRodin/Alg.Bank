#include<iostream>
using namespace std;
struct Queue {
// int queue[100], n = 100, front = -1, rear = -1;
public:
    int *queue;
    int front;
    int rear;
    int capacity; //equivalent to n

    Queue(int cap) {
        capacity = cap;
        front = rear = -1;
        queue = new int[capacity]; //dynamic allocation of memory
    }

    void enqueue(int val)
    {
        if (rear == capacity - 1)
        {
            cout << "queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            queue[rear] = val;
        }
}

void dequeue() {
    if(front == -1 || front > rear) {
        cout << "queue is empty" << endl;
    }
    else {
        cout << "element deleted from the queue: " << queue[front] << endl;
        front++;
    }
}

int getFront() {
    if(front == -1 || front> rear) {
        return 0;
    }
    else {
        return queue[front];
    }
}

void display() {
     if(front == -1 || front > rear) {
        cout << "queue is empty"<< endl;
     };
    for(int i = front; i <= rear; i++) {
        cout << "the element at index" << i << "=" << queue[i] << endl;
    }
}
};

int main() {
    Queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}