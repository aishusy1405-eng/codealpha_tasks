#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Transaction
{
public:
    string type;
    double amount;

    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }
};

class Account
{
public:
    int accountNumber;
    double balance;
    vector<Transaction> history;

    Account(int number)
    {
        accountNumber = number;
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposit successful!\n";
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            history.push_back(Transaction("Withdrawal", amount));
            cout << "Withdrawal successful!\n";
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }

    void showBalance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }

    void showTransactions()
    {
        cout << "\n--- Transaction History ---\n";

        if (history.empty())
        {
            cout << "No transactions yet.\n";
            return;
        }

        for (int i = 0; i < history.size(); i++)
        {
            cout << history[i].type
                 << " : Rs. " << history[i].amount << endl;
        }
    }
};

class Customer
{
public:
    string name;
    int customerId;
    Account account;

    Customer(string n, int id, int accNo)
        : account(accNo)
    {
        name = n;
        customerId = id;
    }

    void showCustomer()
    {
        cout << "\n--- Customer Information ---\n";
        cout << "Customer Name: " << name << endl;
        cout << "Customer ID: " << customerId << endl;
        account.showBalance();
    }
};

int main()
{
    string name;
    int customerId, accountNumber;
    int choice;
    double amount;

    cout << "===== BANKING SYSTEM =====\n";

    cout << "Enter Customer Name: ";
    cin >> name;

    cout << "Enter Customer ID: ";
    cin >> customerId;

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    Customer customer(name, customerId, accountNumber);

    cout << "\nAccount created successfully!\n";

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Customer Information\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            customer.showCustomer();
            break;

        case 2:
            cout << "Enter deposit amount: ";
            cin >> amount;

            if (amount > 0)
                customer.account.deposit(amount);
            else
                cout << "Invalid amount!\n";

            break;

        case 3:
            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (amount > 0)
                customer.account.withdraw(amount);
            else
                cout << "Invalid amount!\n";

            break;

        case 4:
            customer.account.showBalance();
            break;

        case 5:
            customer.account.showTransactions();
            break;

        case 6:
            cout << "Thank you for using Banking System!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}