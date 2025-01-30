#include<iostream>
using namespace std;
int queue[100], n = 100, front = -1, rear = -1;

void enqueue(int val) {
    if(rear == n-1) {
        cout << "queue is full" << endl;
    }
    else {
        if(front== -1) {
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


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();
    display();

    return 0;
}