#include<iostream>
using namespace std;

struct Student {
    int code;
    string name;
    string school;
    string level;
    int age;
    Student *next;
    Student(int c, string n, string sc, string l, int a) {
        code = c;
        name = n;
        school = sc;
        level = l;
        age = a;
    }
};

void display(Student *head) {
    while(head != NULL) {
        cout<<head->code<<" "<<head->name<<" "<<head->school<<" "<<head->level<<" "<<head->age<<endl;
        head = head->next;
    }
    cout << "NULL" << endl;
}


