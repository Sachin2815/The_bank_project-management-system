#include <iostream>
#include <cstring>

using namespace std;

// Account class
class Account {
    string name;
    string mobile;
    string pin;
    double balance;
    int accountNumber;

public:
    Account(string name, string mobile, string pin) {
        static int nextAccountNumber = 1;

        this->name = name;
        this->mobile = mobile;
        this->pin = pin;
        this->balance = 0;
        this->accountNumber = nextAccountNumber++;
    }

    // Getters
    string getName() const {
        return name;
    }

    string getMobile() const {
        return mobile;
    }

    string getPin() const {
        return pin;
    }

    double getBalance() const {
        return balance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    // Setters
    void setName(string name) {
        this->name = name;
    }

    void setMobile(string mobile) {
        this->mobile = mobile;
    }

    void setPin(string pin) {
        this->pin = pin;
    }

    // Methods
    bool verifyPin(string pin) const {
        return this->pin == pin;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of $" << amount << " was successful." << endl;
    }

    void withdraw(double amount) {
        if (balance < amount) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " was successful." << endl;
        }
    }

    void display() const {
        cout << "Account Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Mobile: " << mobile << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Bank class
class Bank {
    Account* accounts[100];
    int numberOfAccounts;

public:
    Bank() {
        numberOfAccounts = 0;
    }

    // Methods
    void openAccount() {
        string name, mobile, pin;

        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your mobile number: ";
        getline(cin, mobile);
        cout << "Enter your PIN number (4 digits): ";
        getline(cin, pin);

        Account* account = new Account(name, mobile, pin);
        accounts[numberOfAccounts++] = account;

        cout << "Account created successfully." << endl;
        cout << "Your account number is: " << account->getAccountNumber() << endl;
    }

    Account* getAccount(int accountNumber) const {
        for (int i = 0; i < numberOfAccounts; i++) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                return accounts[i];
            }
        }
        return NULL;
    }

    void showAccountDetails(int accountNumber, string pin) const {
        Account* account = getAccount(accountNumber);

        if (account == NULL) {
            cout << "Invalid account number." << endl;
        } else if (!account->verifyPin(pin)) {
            cout << "Invalid PIN number." << endl;
        } else {
            account->display();
        }
    }
};
int main() {
    Bank bank;

    int choice;
    int accountNumber;
    string pin;

    do {
        cout << "\nWelcome to the Bank!" << endl;
        cout << "1. Open an account" << endl;
        cout << "2. Display account details" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                bank.openAccount();
                break;

            case 2:
                cout << "Enter your account number: ";
                cin >> accountNumber;
                cout << "Enter your PIN number: ";
                cin >> pin;
                bank.showAccountDetails(accountNumber, pin);
                break;

            case 3:
                cout << "Thank you for using the Bank!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
