#include <iostream>
#include <string>
using namespace std;
class students_data
{
private:
    float sum = 0;
    string name;
    int marks[3];

public:
    void input()
    {
        cout << "Enter the student name" << endl;
        cin >> name;
        cout << "Enter the marks of student in all books" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter the marks of book" << i + 1 << " " << endl;
            cin >> marks[i];
        }
    }
    void calculate()
    {

        for (int i = 0; i < 3; i++)
        {
            sum = sum + marks[i];
        }
    }
    void display()
    {
        cout << "Student name is " << name << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Marks students in book" << i + 1 << ": " << marks[i] << endl;
        }

        cout << "The total marks of student: " << sum << endl;
    }
};

int main()
{
    students_data s1;
    s1.input();
    s1.calculate();
    s1.display();
    return 0;
}