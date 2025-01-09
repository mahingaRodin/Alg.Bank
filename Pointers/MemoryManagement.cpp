#include<iostream>
using namespace std;

int main() {
    // step 1: take user input the size of array
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // step 2: create a dynamic array of that size
    int *arr = new int[size];

//step 3 : take user input for array elements

  cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

// Step 4 : user pointers to find the max , min value and sum
    int *ptr = arr;//pointer to traverse the array 
    int max = *ptr, min = *ptr, sum = 0;

    for (int i = 0; i < size;) {
        if(*(ptr + i) > max) max = *(ptr + i);
        if(*(ptr + i) < min) min = *(ptr + i);
        sum += *(ptr + i);
    }

//step 5: display the results
    cout << "maximum: " << max << endl;
    cout << "minimum: " << min << endl;
    cout<<"sum: "<<sum<<endl;

    //step 6: deallocate memory
    delete[] arr;
    cout << "memory deallocated successfully." << endl;

    return 0;
}