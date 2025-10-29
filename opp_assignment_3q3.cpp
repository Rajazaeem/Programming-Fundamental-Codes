#include <iostream>
#include <string>

using namespace std;

class employee
{
private:
    string name;
    string number;
    int day;
    int month;
    int year;

public:
    employee()
    {
        name = "";
        number = "";
        day = 0;
        month = 0;
        year = 0;
    }

    void setDetails(string name, string number, int day, int month, int year)
    {
        this->name = name;
        this->number = number;
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void input()
    {
        string name, number, hire_date;
        cout << "Enter the name of employee: ";
        getline(cin, name);
        cout << "Enter the Phone number of employee: ";
        getline(cin, number);
        cout << "-----------Enter the hire date of employee in (dd/mm/yyyy) format-----------\n";
        cout << "Enter the day: ";
        cin >> day;
        cout << "Enter the month: ";
        cin >> month;
        cout << "Enter the year: ";
        cin >> year;

        setDetails(name, number, day, month, year);
    }

    void display()
    {
        cout << "Name of employee: " << name << endl;
        cout << "Number of employee: " << number << endl;
        cout << "Employee Hire Date: " << day << "/" << month << "/" << year << endl;
    }
};

class shift_supervisor : public employee
{
private:
    float anual_salary;
    float anual_production_bonus;

public:
    shift_supervisor()
    {
        anual_salary = 0;
        anual_production_bonus = 0;
    }
    void setDetails(float anual_salary, float anual_production_bonus)
    {
        this->anual_salary = anual_salary;
        this->anual_production_bonus = anual_production_bonus;
    }

    void input()
    {
        employee::input();
        int anual_salary;
        float anual_production_bonus;
        cout << "Enter the anual salary: ";
        cin >> anual_salary;
        cout << "Enter the anual production bonus: ";
        cin >> anual_production_bonus;
        setDetails(anual_salary, anual_production_bonus);
    }
    void display()
    {
        cout << "\n---------- Supervisor Details ----------\n"
             << endl;
        employee::display();
        cout << "Anual salary: " << anual_salary << endl;
        cout << "Anual production bonus: " << anual_production_bonus << endl;
    }
};

int main()
{
    shift_supervisor s1;
    s1.input();
    s1.display();
    return 0;
}