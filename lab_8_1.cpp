#include <iostream>
#include <string>

using namespace std;

class A
{

private:
public:
    A()
    {
        cout << "constructor call of A class" << endl;
    }
    ~A()
    {
        cout << "destructor call of A class" << endl;
    }
    void display()
    {
        cout << "this is a class A" << endl;
    }
};
class B
{
private:
    A objA;

public:
    B()
    {
        cout << "constructor call of class B" << endl;
    }
    ~B()
    {
        cout << "destructor call of class B" << endl;
    }
    void display()
    {
        cout << "This is the class B" << endl;
        objA.display();
    }
};

int main()
{
    B objB;
    objB.display();

    return 0;
}