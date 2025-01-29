#include<iostream>
#include<queue>

using namespace std;

int main() {
    queue<int> numbers;

    cout<<"size: "<<numbers.size()<<endl;
    if(numbers.empty()) {
        cout << "Queue is empty" << endl;
    }

    numbers.push(10);
    cout<<"size: "<<numbers.size()<<endl;
    if(!numbers.empty()) {
        cout<<"Queue is not empty"<<endl;
    }

    cout << "front: " <<numbers.front() << endl;
    cout<<"back: "<<numbers.back()<<endl;

    return 0;
}