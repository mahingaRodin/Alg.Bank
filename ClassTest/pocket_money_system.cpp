#include <iostream>
#include <cstring>
#include <ctime>
#include <limits>

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
        int year;
        sscanf(dob, "%*d/%*d/%d", &year);
        if (year > 2025) {
            cout << "Error: Invalid DOB. Year cannot be after 2025." << endl;
            return;
        }

        Customer* newCustomer = new Customer();
        newCustomer->code = code;
        for (int i = 0; name[i] != '\0'; ++i) {
            newCustomer->name[i] = name[i];
        }
        newCustomer->name[strlen(name)] = '\0';
        for (int i = 0; dob[i] != '\0'; ++i) {
            newCustomer->dob[i] = dob[i];
        }
        newCustomer->dob[strlen(dob)] = '\0';
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
    }

    void withdraw(int customerCode, int amount, const char* date) {
        Customer* temp = customerList;
        while (temp != NULL) {
            if (temp->code == customerCode) {
                if (temp->balance >= amount) {
                    temp->balance -= amount;
                    addTransaction(customerCode, "withdraw", amount, date);
                    cout << "Withdrawal successful. New balance: " << temp->balance << endl;
                } else {
                    cout << "Insufficient balance." << endl;
                }
                return;
            }
            temp = temp->next;
        }
    }

    void addTransaction(int customerCode, const char* transactionType, int amount, const char* date) {
        Transaction* newTransaction = new Transaction();
        newTransaction->id = transactionList ? transactionList->id + 1 : 1;
        newTransaction->customerCode = customerCode;
        for (int i = 0; transactionType[i] != '\0'; ++i) {
            newTransaction->transactionType[i] = transactionType[i];
        }
        newTransaction->transactionType[strlen(transactionType)] = '\0';
        newTransaction->amount = amount;
        for (int i = 0; date[i] != '\0'; ++i) {
            newTransaction->date[i] = date[i];
        }
        newTransaction->date[strlen(date)] = '\0';
        newTransaction->next = transactionList;
        transactionList = newTransaction;
    }

    const char* getCurrentDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        static char date[11];
        snprintf(date, sizeof(date), "%02d/%02d/%04d", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
        return date;
    }

    bool isValidIntInput(int &input) {
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid input. Please enter a valid integer." << endl;
            return false;
        }
        return true;
    }

    bool isValidDob(const char* dob) {
        int day, month, year;
        if (sscanf(dob, "%d/%d/%d", &day, &month, &year) != 3 || year > 2025) {
            cout << "Error: Invalid DOB. Year cannot be after 2025." << endl;
            return false;
        }
        return true;
    }
};

int main() {
    PocketMoneySystem system;
    int choice;
    while (true) {
        cout << "1. Add customer\n2. View customers\n3. Deposit\n4. Withdraw\n5. Check balance\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            int code, balance;
            char name[100], dob[11];
            cout << "Enter code: ";
            while (!system.isValidIntInput(code)) {}
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter DOB (dd/mm/yyyy): ";
            cin >> dob;
            while (!system.isValidDob(dob)) {
                cout << "Enter DOB (dd/mm/yyyy): ";
                cin >> dob;
            }
            cout << "Enter balance: ";
            while (!system.isValidIntInput(balance)) {}
            system.addCustomer(code, name, dob, balance);
        } else if (choice == 2) {
            system.viewCustomers();
        } else if (choice == 3) {
            int code, amount;
            cout << "Enter customer code: ";
            while (!system.isValidIntInput(code)) {}
            cout << "Enter amount to deposit: ";
            while (!system.isValidIntInput(amount)) {}
            const char* date = system.getCurrentDate();
            system.deposit(code, amount, date);
        } else if (choice == 4) {
            int code, amount;
            cout << "Enter customer code: ";
            while (!system.isValidIntInput(code)) {}
            cout << "Enter amount to withdraw: ";
            while (!system.isValidIntInput(amount)) {}
            const char* date = system.getCurrentDate();
            system.withdraw(code, amount, date);
        } else if (choice == 5) {
            int code;
            cout << "Enter customer code: ";
            while (!system.isValidIntInput(code)) {}
            system.viewCustomers();
        } else if (choice == 6) {
            break;
        }
    }
    return 0;
}
