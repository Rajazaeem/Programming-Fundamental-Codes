#include<iostream>
#include<string>

using namespace std;

class A
{
    public:
    virtual void display()=0;
        
};
class B : public A
{
    public:
    void display()
    {
        cout<<"This is class B: "<<endl;
    }
};
class C : public A
{
    public:
    void display()
    {
        cout<<"This is class C: "<<endl;
    }
};  

int main()
{
    A* a = new B();
    a->display();
    a = new C();
    a->display();

    return 0;
}