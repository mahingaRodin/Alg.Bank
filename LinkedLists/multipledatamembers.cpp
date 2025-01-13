#include <iostream>
using namespace std;

// Define the Student class
class Student {
public:
    int id;         // Unique ID for the student
    int age;        // Age of the student
    string name;    // Name of the student
    Student* next;  // Pointer to the next student in the linked list

    // Constructor to initialize a student object
    Student(int id, int age, string name) {
        this->id = id;
        this->age = age;
        this->name = name;
        this->next = NULL; // Initialize the next pointer to null
    }
};

// Function to display the details of all students in the linked list
void display(Student* head) {
    // Traverse through the list until reaching the end
    while (head != NULL) {
        // Print the current student's details
        cout << "ID: " << head->id << ", Name: " << head->name << ", Age: " << head->age << endl;
        head = head->next; // Move to the next student
    }
}

int length(Student* head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

void insertNewStudent(Student **head, int id, int age, string name) {
    Student *newStudent = new Student(id, age, name);
    newStudent->next = *head;
    *head = newStudent;
}

int main() {
    // Create the first student as a stack object
    Student n1(1, 17, "Rodin");
    Student n2(2, 18, "Patrick");

    // Link the first student to the second student
    n1.next = &n2;

    // Set the head pointer to the start of the list
    Student* head = &n1;

    // Dynamically create the third and fourth students
    Student* n3 = new Student(3, 19, "James");
    Student* n4 = new Student(4, 20, "Joseph");

    

    // Link the second student to the third, and the third to the fourth
    n2.next = n3;
    n3->next = n4;
    //count the number of students in the linked list
    cout << "the length of the linked list is " << length(head) << endl;
    // Display the linked list of students
    display(head);

    //insert a new student
    cout << "The inserted student is " << insertNewStudent(&head, 1, 23, "Mugisha") << endl;
    display(head);
    return 0; 
}
