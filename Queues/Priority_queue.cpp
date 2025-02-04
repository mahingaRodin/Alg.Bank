#include <iostream>

#define MAX_SIZE 100  // Maximum size of priority queue

class PriorityQueue {
private:
    int heap[MAX_SIZE];  // Array to store heap elements
    int size;  // Current size of the heap

    // Helper function to swap two elements
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Heapify up (maintains heap property after insertion)
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Heapify down (maintains heap property after deletion)
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Constructor
    PriorityQueue() {
        size = 0;
    }

    // Insert an element into the priority queue
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
        int maxValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxValue;
    }

    // Get the highest priority element without removing it
    int top() {
        if (size == 0) {
            std::cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Check if the queue is empty
    bool empty() {
        return size == 0;
    }

    // Get the size of the priority queue
    int getSize() {
        return size;
    }
};

// Main function to test the priority queue
int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(40);
    pq.push(30);
    pq.push(50);
    pq.push(20);

    std::cout << "Top element: " << pq.top() << std::endl;  // Output: 50

    while (!pq.empty()) {
        std::cout << "Removing: " << pq.pop() << std::endl;
    }

    return 0;
}
