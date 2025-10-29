#include <iostream>
#include <string>

using namespace std;

class student
{
protected:
    int id;
    string name;
    float marks;

public:
    student() {}
    void setdata(int id, string name, float marks)
    {
        this->id = id;
        this->name = name;
        this->marks = marks;
    }
};

class result : public student
{
public:
    void display() const
    {
        cout << "The name of the student is " << this->name << endl
             << "Id of the student is " << this->id << endl
             << "Marks of the student is " << this->marks << endl;
    }
};

int main()
{
    int id;
    string name;
    float marks;
    result r;
    cout << "Enter the name of the student: ";
    getline(cin, name);
    cout << "Enter the id of the student: ";
    cin >> id;
    cout << "Enter the marks of the student: ";
    cin >> marks;
    cout << "\n------------The data of the student is---------------\n" << endl;
    r.setdata(id, name, marks);
    r.display();

    return 0;
}