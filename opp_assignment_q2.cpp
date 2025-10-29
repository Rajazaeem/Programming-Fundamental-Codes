#include <iostream>
#include <string>

using namespace std;

// Base class to represent a general employee
class employee
{
private:
    string name;       // Employee's name
    string number;     // Employee's phone number
    string hire_date;  // Employee's hire date

public:
    // Default constructor
    employee() {}

    // Parameterized constructor to initialize employee attributes
    employee(string name, string number, string hire_date)
    {
        this->name = name;
        this->number = number;
        this->hire_date = hire_date;
    }

    // Function to display employee details
    void display()
    {
        cout << "Name of employee: " << name << endl;
        cout << "Number of employee: " << number << endl;
        cout << "Employee Hire Date: " << hire_date << endl;
    }
};

// Derived class from employee that represents a production worker
class production_worker : public employee
{
private:
    int shift;               // Shift type: 1 for day, 2 for night
    double hourly_pay_rate;  // Pay rate per hour

public:
    // Default constructor
    production_worker() {}

    // Parameterized constructor that also calls the base class constructor
    production_worker(string name, string number, string hire_date, int shift, double hourly_pay_rate)
        : employee(name, number, hire_date)
    {
        this->shift = shift;
        this->hourly_pay_rate = hourly_pay_rate;
    }

    // Function to display full details of the production worker
    void display()
    {
        cout << "\n---------- Details ----------" << endl;
        employee::display();  // Call base class display to show name, number, and hire date

        // Display shift type based on the shift value
        if (shift == 1)
        {
            cout << "Shift: Day Shift" << endl;
        }
        else if (shift == 2)
        {
            cout << "Shift: Night Shift" << endl;
        }
        else
        {
            cout << "Please enter the right shift" << endl;
        }

        // Display hourly pay rate
        cout << "Hourly Pay Rate: " << hourly_pay_rate << endl;
    }
};

int main()
{
    // Variables to store user input
    string n;       // Name
    string date;    // Hire date
    string num;     // Phone number

    // Take input from the user
    cout << "Enter the name of employee: ";
    getline(cin, n);

    cout << "Enter the Phone number of employee: ";
    cin >> num;

    // Clear input buffer before using getline again
    cout << "Enter the hire date of employee in (dd/mm/yyyy) format: ";
    cin.ignore();  // Required after using cin >> to avoid skipping input
    getline(cin, date);

    int s;      // Shift
    double hr;  // Hourly rate

    // Get shift and validate input
    cout << "Enter the shift of employee (1 for day shift and 2 for night shift): ";
    cin >> s;

    while (s != 1 && s != 2)
    {
        cout << "Enter the correct shift of employee (1 for day shift and 2 for night shift): ";
        cin >> s;
    }

    // Get hourly pay rate
    cout << "Enter the hourly pay rate of employee: ";
    cin >> hr;

    // Create production_worker object with user input
    production_worker p(n, num, date, s, hr);

    // Display the worker's details
    p.display();

    return 0;
}