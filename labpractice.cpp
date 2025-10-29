#include <iostream>
#include <string>

using namespace std;

class students
{
private:
    string name;
    int id;
    float marks1, marks2, marks3;

public:
    students()//constructor
    {
        name = "Unknown";
        id = 0;
        marks1 = 0.0;
        marks2 = 0.0;
        marks3 = 0.0;
    }
    void data(string n, int i, float m1, float m2, float m3)//setter function
    {
        name = n;
        id = i;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }
    float total()//calculate marks
    {
        return marks1 + marks2 + marks3;
    }
    void display()//displaying all data/ getter function
    {
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << total() << endl;
    }
};

int main()
{
    students s1;
    string n;
    int i;
    float m1, m2, m3;
    cout << "Enter the name of student: ";
    getline(cin, n);
    cout << "Enter the id of student: ";
    cin >> i;
    while (i <= 0)//loop for validation student id
    {
        cout << "Invalid id. Please enter a positive integer: ";
        cin >> i;
    }
    cout << "Enter the marks of student in three subjects: " << endl;
    cout << "Enter the marks of student in English: ";
    cin >> m1;
    while (m1 < 0 || m1 > 100)//loop for validation student id
    {
        cout << "Invalid marks. Please enter marks between 0 and 100: ";
        cin >> m1;
    }
    cout << "Enter the marks of student in opp: ";
    cin >> m2;
    while (m2 < 0 || m2 > 100)//loop for validation student id
    {
        cout << "Invalid marks. Please enter marks between 0 and 100: ";
        cin >> m2;
    }
    cout << "Enter the marks of student in cyber security: ";
    cin >> m3;
    while (m3 < 0 || m3 > 100)//loop for validation student id
    {
        cout << "Invalid marks. Please enter marks between 0 and 100: ";
        cin >> m3;
    }
    s1.data(n, i, m1, m2, m3);//function calling
    float Total = s1.total();//storing the return data in variable
    s1.display();//function calling
    return 0;
}