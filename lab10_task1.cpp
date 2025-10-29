#include<iostream>
#include<string>

using namespace std;

class A
{
    public:
    virtual void display()
    {
        cout<<"This is class A: "<<endl;
    }
        
};
class B:public A
{
    public:
    void display()
    {
        cout<<"This is class B: "<<endl;
    }
        
};
class C:public A
{
    public:
 
    void display()
    {
        cout<<"This is class C: "<<endl;
    }
        
};

int main()
{
    A objA;
    B objB;
    C objC;
    A *objD;
    objD=&objA;
    objD->display();
    objD=&objB;
    objD->display();
    objD=&objC;
    objD->display();
    return 0;
}