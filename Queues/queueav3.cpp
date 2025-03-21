#include<iostream>
using namespace std;
struct Queue {
// int queue[100], n = 100, front = -1, rear = -1;
public:
    int *queue;
    int front;
    int rear;
    int capacity; //equivalent to n
    int size;

    Queue(int cap) {
        capacity = cap;
        front = rear = -1;
        queue = new int[capacity]; //dynamic allocation of memory
        size = 0;
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
        size++;
}

void dequeue() {
     if( isEmpty()
        // front == -1 || front > rear
        ) {
        cout << "queue is empty" << endl;
    }
    else {
        cout << "element deleted from the queue: " << queue[front] << endl;
        front++;
    }
    size--;
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

int count {
    return size;
}

bool isEmpty() {
    return size == 0;
}

bool isFull() {
    return size == capacity;
}
int main() {
    // Queue q(5);
    Queue *q = new Queue(5);
    cout << "start adding elements" << endl;
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);
    q->enqueue(60);

    q->display();

    q->dequeue();
    q->dequeue();
    q->display();

    return 0;
}