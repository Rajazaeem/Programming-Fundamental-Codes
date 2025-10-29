#include <iostream>
#include <string>

using namespace std;

class date
{
private:
    int day, month, year;

public:
    void entries(int a, int b, int c)
    {
        day = a;
        month = b;
        year = c;
    }
    void details()
    {
        cout << "Date (dd/mm/yyyy) : ";
        cout << day << "/" << month << "/" << year;
    }
};
int main()
{
    date d;
    int day, month, year;
    do
    {
        cout << "Enter the date (day month year)" << endl;
        cout << "Enter day: ";
        cin >> day;
        cout << "Month: ";
        cin >> month;
        cout << "year: ";
        cin >> year;
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 2025 || year > 2050)
        {
            cout << "Error: Invalid date. Please enter a valid date." << endl;
            cout << "Day in range (1-31) month in range (1-12) year in range (2025-2050)" << endl;
        }
    } while (day < 1 || day > 31 || month < 1 || month > 12 || year < 2025 || year > 2050);
    d.entries(day, month, year);
    d.details();
    return 0;
}
