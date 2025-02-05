#include<iostream>
using namespace std;

//implementation of a queue using a linked list 

class Node {
	int data;
	Node* next;
	Node(int x) {
		this->data = x;
		next = NULL;
	}
};


class Queue {
	Node* head;
	Node* tail;
	int size;
	
	public:
		Queue() {
			head = NULL;
			tail = NULL;
			size = 0;
		}
		itn getSize() {
			return size;
		}
		int count() {
			return size;
		}
		bool isEmpty() {
			return size == 0;
		}
};

void enqueue(int ele) {
    Node *newNode = new Node(ele);
    if(isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

int dequeue() {
    if(isEmpty()) {
        cout << "queue is empty" << endl;
        return 0;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    size--;
}

int front() {
    if(isEmpty()) {
        return 0;
    }
    return head->data;
}

void display() {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
}

