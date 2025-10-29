#include <iostream>
#include <string>

using namespace std;

class student{
    private:
    string *name;
    int age;

    public:
    student()
    {
        *name = "Unknown";
        age = 0;
    }
    student (string n, int a){
        name = new string(n);
        age = a;

    }
    student (student &s){
        name = new string (*(s.name));
        age = s.age;
    }

    void display()
    {
        cout<<"Name: "<<*name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<endl;
    }

    ~student()
    {
        delete name;
        cout<<"Destructor is called."<<endl;
    }

};

int main()
{
    student S1("Zaeem Furqan", 69);
    S1.display();
    student S2(S1);
    S2.display();

    return 0;
}