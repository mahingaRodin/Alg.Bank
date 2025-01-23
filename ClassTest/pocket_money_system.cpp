#include<iostream>
using namespace std;

struct Customer {
    int code;
    string name;
    string dob;
    int balance;
    Customer *next;
};


struct Transaction {
    int id;
    int customerCode;
    string transcactionType;
    int amount;
    string date;
    Transaction *next;
};

class PocketMoneySystem {
    private:
        Customer* customerList;
        Transaction* transcationList;
    
    public:
        customerList = NULL;
        transactionList = NULL;
}

void addCustomer(int code, string name, string dob, int balance) {
    Customer *newCustomer = new Customer();
    newCustomer->code = code;
    newCustomer->name = name;
    newCustomer->dob = dob;
    newCustomer->balance = balance;
    newCustomer->next = customerList;
    customerList = newCustomer;
    cout<<"Customer added successfully!"<<endl;
}


void viewCustomers() {
    Customer *temp = customerList;
    if(temp == NULL) {
        cout<<"No customers found!"<<endl;
        return;
    }

    while(temp != NULL) {
        cout<<"Code: "<<temp->code<<" , Name: "<<temp->name<<" , DOB: "<<temp->dob<<" , Balance: "<<temp->balance<<endl;
        temp = temp->next;
    }
}