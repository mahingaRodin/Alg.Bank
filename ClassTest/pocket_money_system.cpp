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


void deposit(int customerCode, int amount, string date) {
    Customer* temp = customerList;
    while(temp != NULL) {
        if(temp->code == customerCode) {
            temp->balance += amount;
            addTransaction(customerCode, "deposit", amount, date);
            cout<<"Deposit successful. New balance: "<<temp->balance<<endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Customer Not Found." << endl;
}

void withdraw(int customerCode, int amount, string date) {
    Customer *temp = customerList;
    while(temp !=NULL) {
        if(temp->code == customerCode) {
            if(temp->balance >= amount) {
                temp->balance -= amount;
                addTransaction(customerCode, "withdraw", amount, date);
                cout<<"Withdraw successful. New balance: "<<temp->balance<<endl;
                return;
            }
            else {
                cout << "Insufficient balance";
                return;
            }
        }
        temp = temp->next;

    }
    cout << "Customer Not Found" << endl;
}
