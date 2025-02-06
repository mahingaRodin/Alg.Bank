#include<iostream>
using namespace std;


class CirlceQ {
    private:
        int *arr;
        int front, rear, size;


        public:
        CirlceQ(int s) {
            size = s;
            arr = new int[size];
            front = rear = -1;
        }

        //destructor to clean up the memory
    ~CirlceQ() { delete[] arr; }

    //function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    //function to check if the queue is empty 
    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value ) {
        if(isFull()) {
            cout << "queue is full" << endl;
            return;
        }

        if (front == -1 ) { //first element to enqueue
            front = 0;
            rear = 0;
        } else if (rear == size -1  && front != 0) {
            rear = 0; //wrapping around
        } else {
            rear++;
        }

        arr[rear] = value;
        cout << value << " enqueued to queue" << endl;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "queue is empty" << endl;
            return -1;
        }

        int dequeuedVal = arr[front];
        if(front == rear) {
            front = rear = -1;
        }
        else if (front == size -1) {
            front = 0;
        } else {
            front++;
        }
        return dequeuedVal;
    }

    void display() {
        if(isEmpty()) {
            cout << "queue is empty!" << endl;
        }
        cout << "queue elements: ";
        if(rear >= front ) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << arr[i]<<" ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};


int main() {
    CirlceQ q(5);

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

     q.display();

    q.enqueue(60);
    q.display();

    return 0;
    
}