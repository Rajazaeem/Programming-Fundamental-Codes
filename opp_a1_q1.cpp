#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount
{
private:
    long account_Number;
    string account_Holder;
    double balance;

public:
    // Default Constructor
    BankAccount()
    {
        account_Number = 0;
        balance = 0.0;
        account_Holder = "None";
    }
    // Parameterized Constructor
    BankAccount(long acc_No, string acc_Hold, double bal)
    {
        account_Number = acc_No;
        account_Holder = acc_Hold;
        balance = bal;
    }

    // Deposit functions
    void deposit(double amount, string description)
    {
        balance += amount;
        cout << "Deposit Successful.\n";
        cout << "Transaction Description: " << description << endl;
    }
    // Withdraw functions
    void withdraw(double amount)
    {
        balance -= amount;
    }
    // Get balance
    double getBalance()
    {
        return balance;
    }

    // Display account details
    void displayAccountDetails()
    {
        cout << "Account Number: " << account_Number << endl;
        cout << "Account Holder: " << account_Holder << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

int main()
{
    // Set precision for currency output
    cout << fixed << setprecision(2);
    double ac_n;
    string ac_h;
    cout << "Enter Account Number: ";
    cin >> ac_n;
    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, ac_h);

    // Creating an account
    BankAccount acc(ac_n, ac_h, 30000); // initial balance

    int choice;
    double amount;
    string description;
     string rep;

    cout << "\n-------Welcome to ZF Bank Limited-------\n";
    acc.displayAccountDetails();
    cout << endl;

    do
    {
        cout << "-------Select a transaction-------" << endl
             << "1. Deposit" << endl
             << "2. Withdraw" << endl
             << "3. Check Balance" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            cout << "Enter a description: ";
            getline(cin, description);
            acc.deposit(amount, description);
            cout << "Updated Balance: $" << acc.getBalance() << endl;
            break;

        case 2:

            cout << "Enter withdrawal amount: ";
            cin >> amount;
            do
            {
                if (amount > acc.getBalance())
                {
                    cout << "Insufficent balance! Please enter a valid amount" << endl;
                    cin >> amount;
                }
            } while (amount > acc.getBalance()); // loop until valid amount is entered
            acc.withdraw(amount);
            cout << "Widthrawl successful! \nUpdated Balance: $" << acc.getBalance() << endl;
            break;

        case 3:
            cout << "Current Balance: $" << acc.getBalance() << endl;
            break;

        default:
            cout << "Error! Invalid choice. Please try again."<<endl;
            break;
        }

        cout << "\nDo you want to perform another transaction? (Yes/No): ";
        cin >> rep;

    } while (rep == "y"|| rep == "Y" || rep == "yes" || rep == "Yes" || rep == "YES");

    cout << "Thank you for using ZF Bank."<<endl;
    return 0;
}
