#include<iostream>
#include<string>

using namespace std;

class student
{
    private:
        string name;
        int age;
    public:
    student(){
        name="unknown";
        age=0;
    }
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
    s1.setData(20,"Zaeem Furqan");
    s1.getData();

    return 0;
}