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
    void display()
    {
        cout << "The name of the student is " << this->name << endl
             << "Id of the student is " << this->id << endl;
    }
};

class result : public student
{
public:
    void display()
    {
        student::display();
        cout << "Marks of the student is " << this->marks << endl;
    }
};

int main()
{
    result r;
    cout << "\n------------The data of the student is---------------\n"
         << endl;
    r.setdata(247169, "Zaeem Furqan", 9.9);
    r.display();

    return 0;
}