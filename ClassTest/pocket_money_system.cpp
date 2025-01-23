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
    string transactionType;
    int amount;
    string date;
    Transaction *next;
};

class PocketMoneySystem {
    private:
        Customer* customerList;
        Transaction* transactionList;
    
    public:
        PocketMoneySystem() {
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

 void checkBalance(int customerCode) {
        Customer* temp = customerList;
        while (temp != NULL) {
            if (temp->code == customerCode) {
                cout << "Balance: " << temp->balance << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Customer not found." << endl;
    }


private:

void addTransaction(int customerCode, string transactionType, int amount, string date) {
    Transaction *newTransaction = new Transaction();
    newTransaction->id = rand();
    newTransaction->customerCode = customerCode;
    newTransaction->transactionType = transactionType;
    newTransaction->amount = amount;
    newTransaction->date = date;
    newTransaction->next = transactionList;
    transactionList = newTransaction;
}
};

int main() {
    PocketMoneySystem system;
    int choice;

    do {
        cout << "\nMenu: " << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. View Customers" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Check Balance" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int code;
        string name, dob, date;
        int amount;

        switch(choice) {
            case 1:
            cout << "Enter customer code: ";
            cin >> code;
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter customer date of birth (DD/MM/YYYY): ";
            getline(cin, dob);
            cout << "Enter initial balance: ";
            cin >> amount;
            system.addCustomer(code, name, dob, amount);
            break;

            case 2:
            system.viewCustomers();
            break;

            case 3:
            cout << "Enter customer code: ";
            cin >> code;
            cout << "Enter deposit amount: ";
            cin >> amount;
            cout << "Enter transaction date (DD/MM/YYYY): ";
            cin.ignore();
            getline(cin, date);
            system.deposit(code, amount, date);
            break;

            case 4:
            cout << "Enter customer code: ";
            cin >> code;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            cout << "Enter transaction date (DD/MM/YYYY): ";
            cin.ignore();
            getline(cin, date);
            system.withdraw(code, amount, date);
            break;

            case 5:
                cout << "Enter customer code: ";
                cin >> code;
                system.checkBalance(code);
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice , try again." << endl;
        }
    } while (
        choice != 6);

    return 0;
}
