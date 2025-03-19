#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Method 1: List initialization
    vector<int> vect1 = {1, 2, 3, 4, 5};

    // Method 2: Uniform initialization
    vector<int> vect2{6, 7, 8, 9, 10};

    // Method 3: Constructor initialization
    vector<int> vect3(5, 12);

    cout << "Vector from method 1 = ";
    for (int i : vect1) {
        cout << i << " ";
    }

    cout << "\nVector from method 2 = ";
    for (int i : vect2) {
        cout << i << " ";
    }

    cout << "\nVector from method 3 = ";
    for (int i : vect3) {
        cout << i << " ";
    }

    return 0;
}

