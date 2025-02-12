#include<iostream>
using namespace std;

//queue to gather student/person info

struct Student {
    int code;
    string name;
    int age;
    Student* next;
};

class PersonPriorityQueue {
    private:
        Student* front;

        public:
            PersonPriorityQueue() { front = NULL; }

            void insert(int code, string name, int age) {
                Student *newStudent = new Student{code, name, age, NULL};
                if(!front || age < front->age) {
                    newStudent->next = front;
                    front = newStudent;
                } else {
                    Student *temp = front;
                    while (temp->next && temp->next->age <= age) {
                        temp = temp->next;
                    }
                    newStudent->next = temp->next;
                    temp->next = newStudent;
                }
            }

            void remove() {
                if(!front) {
                    cout << "Queue is empty!\n";
                    return;
                }
                Student *temp = front;
                front = front->next;
                delete temp;
            }

        void display() {
            if(!front) {
                cout << "Queue is empty!\n";
                return;
            }
            Student* temp = front;
            while(temp) {
                cout<<temp->code<<" "<<temp->name<<" "<<temp->age<<endl;
                temp = temp->next;
            }
        }
};


int main() {
    PersonPriorityQueue pq; 
     pq.insert(101, "Alice", 21);
    pq.insert(102, "Bob", 19);
    pq.insert(103, "Charlie", 22);
    pq.display();
    pq.remove();
    pq.display();
    return 0;
}