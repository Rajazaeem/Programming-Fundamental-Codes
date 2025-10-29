#include<iostream>
#include<string>
using namespace std;

class student
{
    private:
    int age;
    string name;
    public:
    void setData(int a, string n)
    {
        name = n;
        age = a;
    }
    void getData()
    {
        cout<<endl<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

int main()
{
    student s1;
    int age;
    string name;

    cout<<"Enter your name: ";
    cin>>name;

    cout<<"Enter your age: ";
    cin>>age;

    while (age <= 0 || age > 200)
    {
        cout<<endl<<"Innalid age! Pease enter valid age (1-150): ";
        cin>>age;
    }
    

    s1.setData(age,name);
    s1.getData();
    return 0;
}