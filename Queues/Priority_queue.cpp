#include<iostream>
using namespace std;

//implementation of the priority queue

#define MAX_SIZE 100


class PriorityQueue{
    private:
    int heap[MAX_SIZE];
    int size;

    void swap(int &a , int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    //heapifyup(to maintain the property after inserttion)
    void heapifyup(int index) {
        int parent = (index - 1) / 2;
        while(index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifydown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if(left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        if(right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if(largest != index) {
            swap(heap[index], heap[largest]);
            heapifydown(largest);
        }
    }

    public:
    //constuctor 
    PriorityQueue() {
        size = 0;
    }
    

    //insert an element into the priority queue
    void push(int value) {
        if (size == MAX_SIZE) {
            std::cout << "Priority Queue is full!\n";
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

       // Remove and return the highest priority element
    int pop() {
        if (size == 0) {
            std::cout << "Priority Queue is empty!\n";
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }

    //get the highest priority 
    int top() {
        if(size == 0) {
            std::cout<<"priority queue is empty";
            return -1;
        }
        return heap[0];
    }

    bool empty() {
        return size == 0;
    }

    //get the size of the priority queue
    int getSize() {
        return size;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(40);
    pq.push(30);
    pq.push(50);
    pq.push(20);

    std::cout << "Top element: " << pq.top() << std::endl;
    
    while(!pq.empty()) {
        std::cout << "Removing: " << pq.pop() << std::endl;
    }

    return 0;
}