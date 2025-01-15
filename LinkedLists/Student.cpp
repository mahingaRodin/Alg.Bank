#include<iostream>
using namespace std;

struct Student {
    int code;
    string name;
    string school;
    string level;
    int age;
    Student *next;
    Student(){}
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

int main() {
    Student *s1 = new Student();
    s1->code = 101;
    s1->name = "Rodin";
    s1->school = "RCA";
    s1->age = 17;

    Student *s2 = new Student(102,"Peter", "RCA", "10", 17);
    Student *s3 = new Student(102,"John", "RCA", "10", 17);
    Student *s4 = new Student(102,"Mike", "RCA", "10", 19);
    s1->next = s2;
    s2->next = s3;
    s3->next = s4;
    s4->next = NULL;
    display(s1);
    return 0;
}
