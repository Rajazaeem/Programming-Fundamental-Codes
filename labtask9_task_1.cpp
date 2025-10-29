#include <iostream>
#include <string>

using namespace std;

class A
{
protected:
    string name;
    int age;

public:
    A(string n, int a)
    {
        name = n;
        age = a;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class B
{
protected:
    string address;
    string phone;

public:
    B(string a, string p)
    {
        address = a;
        phone = p;
    }
    void display()
    {
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
};
class C : public A, public B
{
protected:
    string email;

public:
    C(string n, int a, string a1, string p1, string e) : A(n, a), B(a1, p1)
    {
        email = e;
    }
    void display()
    {
        A::display();
        B::display();
        cout << "Email: " << email << endl;
    }
};

int main()
{
    C obj("ZAEEM FURQAN", 20, "123 Main St", "0335123456", "rajazaeem@gmail.com");
    obj.display();

    return 0;
}
