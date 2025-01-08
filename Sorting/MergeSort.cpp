#include <iostream>
using namespace std;

void merge(int left[], int right[], int arr[], int leftSize, int rightSize) {
    int i = 0, l = 0, r = 0;
    while (l < leftSize && r < rightSize) {
        if (left[l] < right[r]) {
            arr[i++] = left[l++];
        } else {
            arr[i++] = right[r++];
        }
    }

    // Copy remaining elements of the left half
    while (l < leftSize) {
        arr[i++] = left[l++];
    }

    // Copy remaining elements of the right half
    while (r < rightSize) {
        arr[i++] = right[r++];
    }
}

// Recursive function for Merge Sort
void mergeSort(int arr[], int size) {
    if (size < 2) // Base case: An array of size 1 is already sorted
        return;

    int mid = size / 2;

    // Dynamically allocate memory for left and right subarrays
    int* left = new int[mid];
    int* right = new int[size - mid];

    // Fill the left and right subarrays
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Recursively sort the two halves
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted halves
    merge(left, right, arr, mid, size - mid);

    // Free allocated memory
    delete[] left;
    delete[] right;
}

int main() {
    int arr[] = {12, 3, 5, 43, 24, 18, 22};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform Merge Sort
    mergeSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
