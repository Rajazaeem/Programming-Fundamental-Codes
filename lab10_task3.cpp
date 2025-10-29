#include<iostream>
#include<string>

using namespace std;

class A
{
    public:
    static int count;
    A()
    {
        count++;
    }

    static int getcount()
    {
        return count;
    }
    static void display()
    {
        cout<<"This is class A: "<<endl;
    };
        
};

int A::count = 0;
class B:public A
{
    public:
    void display()
    {
        cout<<"This is class B: "<<endl;
    };
};
class C:public A
{
    public:
    void display()
    {
        cout<<"This is class C: "<<endl;
    };
};

int main()
{
    A a1,a2,a3;
   
    a1.display();
   

    return 0;
}