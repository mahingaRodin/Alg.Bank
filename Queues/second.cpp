#include<iostream>
using namespace st;

int queue[100], n = 100, front = -1, rear = -1;

void enqueue() {
    int val;
    if(rear == n - 1) {
        cout<<"Queue Overflow"<<endl;
    } 
    else {
        if(front == -1) {
            front = 0;
            cout<<"Insert the element in queue: ";
            cin >> val;
            rear++;
            queue[rear] = val;
        }
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        cout<<"Queue Underflow ";
        return;
    }
    cout<<"Element deleted from queue is : "<< queue[front] <<endl;
}