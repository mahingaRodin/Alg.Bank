#include <iostream>
using namespace std;

int queue[100], n = 100, front = -1, rear = -1;

void enqueue() {
    int val;
    if (rear == n - 1) {
        cout << "Queue Overflow" << endl;
    } else {
        cout << "Insert the element in queue: ";
        cin >> val;
        if (front == -1) front = 0;
        rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << "Element deleted from queue is: " << queue[front] << endl;
    front++;
    if (front > rear) front = rear = -1;
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

void readFront() {
    if (front == -1) {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << "Element at front: " << queue[front] << endl;
}

int main() {
    int ch;
    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all the elements of queue" << endl;
    cout << "4) Read front element from the queue" << endl;
    cout << "5) Exit" << endl;
    do {
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                readFront();
                break;
            case 5:
                cout << "Exited the queue" << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (ch != 5);
    return 0;
}