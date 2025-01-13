#include<iostream>
using namespace std;

class Student {
    public:
        int id;
        int age;
        string name;
        Stundent *next;

        Student(int id, int age , string name) {
            this->id = id;
            this->age = age;
            this->name = name;
            next = NULL;
        }
}