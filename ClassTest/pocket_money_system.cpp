#include <iostream>
#include <ctime>

using namespace std;

struct Customer {
    int code;
    char name[100];
    char dob[11];
    int balance;
    Customer* next;
};

struct Transaction {
    int id;
    int customerCode;
    char transactionType[10];
    int amount;
    char date[11];
    Transaction* next;
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

    void addCustomer(int code, const char* name, const char* dob, int balance) {
        Customer* newCustomer = new Customer();
        newCustomer->code = code;
        strcpy(newCustomer->name, name);
        strcpy(newCustomer->dob, dob);
        newCustomer->balance = balance;
        newCustomer->next = customerList;
        customerList = newCustomer;
        cout << "Customer added successfully." << endl;
    }

    void viewCustomers() {
        Customer* temp = customerList;
        if (temp == NULL) {
            cout << "No customers found." << endl;
            return;
        }
        while (temp != NULL) {
            cout << "Code: " << temp->code << ", Name: " << temp->name << ", DOB: " << temp->dob << ", Balance: " << temp->balance << endl;
            temp = temp->next;
        }
    }

    void deposit(int customerCode, int amount, const char* date) {
        Customer* temp = customerList;
        while (temp != NULL) {
            if (temp->code == customerCode) {
                temp->balance += amount;
                addTransaction(customerCode, "deposit", amount, date);
                cout << "Deposit successful. New balance: " << temp->balance << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Customer not found." << endl;
    }

    void withdraw(int customerCode, int amount, const char* date) {
        Customer* temp = customerList;
        while (temp != NULL) {
            if (temp->code == customerCode) {
                if (temp->balance >= amount) {
                    temp->balance -= amount;
                    addTransaction(customerCode, "withdraw", amount, date);
                    cout << "Withdrawal successful. New balance: " << temp->balance << endl;
                    return;
                } else {
                    cout << "Insufficient balance." << endl;
                    return;
                }
            }
            temp = temp->next;
        }
        cout << "Customer not found." << endl;
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
    void addTransaction(int customerCode, const char* transactionType, int amount, const char* date) {
        Transaction* newTransaction = new Transaction();
        newTransaction->id = rand();
        newTransaction->customerCode = customerCode;
        strcpy(newTransaction->transactionType, transactionType);
        newTransaction->amount = amount;
        strcpy(newTransaction->date, date);
        newTransaction->next = transactionList;
        transactionList = newTransaction;
    }

    bool isValidIntInput(int &input) {
        if (!(cin >> input)) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return false;
        }
        return true;
    }

    bool isValidYear(int year) {
        if (year > 2025) {
            cout << "Year cannot be later than 2025. Please enter a valid year." << endl;
            return false;
        }
        return true;
    }

    const char* getCurrentDate() {
        time_t t = time(0);
        struct tm *now = localtime(&t);
        static char dateStr[11];
        strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", now);
        return dateStr;
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
        char name[100], dob[11];
        int amount;

        switch (choice) {
        case 1:
            cout << "Enter customer code: ";
            while (!system.isValidIntInput(code)) {}

            cout << "Enter customer name: ";
            cin.ignore();
            cin.getline(name, 100);
            
            cout << "Enter customer date of birth (DD/MM/YYYY): ";
            cin.getline(dob, 11);
            
            cout << "Enter initial balance: ";
            while (!system.isValidIntInput(amount)) {}

            system.addCustomer(code, name, dob, amount);
            break;

        case 2:
            system.viewCustomers();
            break;

        case 3:
            cout << "Enter customer code: ";
            while (!system.isValidIntInput(code)) {}

            cout << "Enter deposit amount: ";
            while (!system.isValidIntInput(amount)) {}

            const char* date = system.getCurrentDate();
            system.deposit(code, amount, date);
            break;

        case 4:
            cout << "Enter customer code: ";
            while (!system.isValidIntInput(code)) {}

            cout << "Enter withdrawal amount: ";
            while (!system.isValidIntInput(amount)) {}

            date = system.getCurrentDate();
            system.withdraw(code, amount, date);
            break;

        case 5:
            cout << "Enter customer code: ";
            while (!system.isValidIntInput(code)) {}

            system.checkBalance(code);
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
