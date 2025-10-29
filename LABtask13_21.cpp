#include<iostream>
#include<string>

using namespace std;

class A
{
    public:
    void display(){
        cout<<"this is a first class"<<endl;
    }
        
};

class B:virtual public A{
};

class C: virtual public A{};
class D:public B,public C{
};



int main()
{
    D obj;
    obj.display();

    return 0;
}