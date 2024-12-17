#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    int accountNumber;
    string name;
    double balance;
    string address;
    Account* next;

    Account(int accNum, string accName, double accBalance, string accAddress) {
        accountNumber = accNum;
        name = accName;
        balance = accBalance;
        address = accAddress;
        next = NULL;
    }
};

// Function to add a new account
void createAccount(Account*& head, int accountNumber, string name, double balance, string address) {
    Account* newAccount = new Account(accountNumber, name, balance, address);
    newAccount->next = head;
    head = newAccount;
}

// Function to display all accounts
void displayAccounts(Account* head) {
    Account* temp = head;
    while (temp != NULL) {
        cout << "----------------------------" << endl;
        cout << "Account Number: " << temp->accountNumber << "\n"
             << "Name: " << temp->name << "\n"
             << "Balance: $" << temp->balance << "\n"
             << "Address: " << temp->address << "\n";
        temp = temp->next;
    }
    cout << "----------------------------" << endl;
}

// Function to search for an account by account number
Account* searchAccount(Account* head, int accountNumber) {
    Account* current = head;
    while (current != NULL) {
        if (current->accountNumber == accountNumber) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    Account* head = NULL;
    string name, address;
    int accountNumber, option, subOption;
    double balance;
    Account* foundAccount = NULL;
    int accountCounter = 1;

    do {
        cout << "\n=== Banking App ===\n";
        cout << "1) Open New Account\n2) View My Account\n3) Check Account Availability\n4) Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter your Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Initial Deposit Amount: ";
                cin >> balance;
                cout << "Enter your Address: ";
                cin.ignore();
                getline(cin, address);

                createAccount(head, accountCounter, name, balance, address);
                cout << "Account created successfully with Account Number: " << accountCounter << "\n";
                accountCounter++;

                do {
                    cout << "\n1) Open another account\n2) Back to homepage\n";
                    cout << "Enter your choice: ";
                    cin >> subOption;

                    if (subOption == 1) {
                        cout << "Enter your Name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter Initial Deposit Amount: ";
                        cin >> balance;
                        cout << "Enter your Address: ";
                        cin.ignore();
                        getline(cin, address);

                        createAccount(head, accountCounter, name, balance, address);
                        cout << "Account created successfully with Account Number: " << accountCounter << "\n";
                        accountCounter++;
                    }
                } while (subOption != 2);
                break;

            case 2:
                cout << "Enter your Account Number: ";
                cin >> accountNumber;
                foundAccount = searchAccount(head, accountNumber);

                if (foundAccount == NULL) {
                    cout << "Account not found!\n";
                } else {
                    cout << "\n--- Account Details ---\n";
                    cout << "Account Number: " << foundAccount->accountNumber << "\n"
                         << "Name: " << foundAccount->name << "\n"
                         << "Balance: $" << foundAccount->balance << "\n"
                         << "Address: " << foundAccount->address << "\n";
                }
                break;

            case 3:
                cout << "Enter Account Number to check availability: ";
                cin >> accountNumber;
                foundAccount = searchAccount(head, accountNumber);

                if (foundAccount == NULL) {
                    cout << "Account Number is available.\n";
                } else {
                    cout << "Account Number is already taken.\n";
                }
                break;

            case 4:
                cout << "Thank you for using the Banking App. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (option != 4);

    return 0;
}
