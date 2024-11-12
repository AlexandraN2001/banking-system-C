#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    // Constructor to initialize the account
    BankAccount(string holder, double initialBalance) {
        accountHolder = holder;
        balance = initialBalance;
    }

    // Method to check the balance
    void checkBalance() {
        cout << "Current balance: $" << balance << endl;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    // Method to display account information
    void displayAccountInfo() {
        cout << "Account holder: " << accountHolder << endl;
        checkBalance();
    }
};

int main() {
    string name;
    double initialDeposit;

    // Ask the user for their name and initial deposit
    cout << "Enter account holder's name: ";
    getline(cin, name);
    cout << "Enter initial deposit: $";
    cin >> initialDeposit;

    // Create a bank account with the name and initial deposit
    BankAccount account(name, initialDeposit);

    int choice;
    do {
        cout << "\nBank Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.checkBalance();
                break;
            case 2: {
                double depositAmount;
                cout << "Enter deposit amount: $";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            }
            case 3: {
                double withdrawAmount;
                cout << "Enter withdrawal amount: $";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            }
            case 4:
                cout << "Exiting system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
