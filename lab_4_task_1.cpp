#include<iostream>
#include<string>

using namespace std;


class student
{
    private:
	string name;
	int age;

	public:
	student()
	{
		cout<<"Enter your name: ";
		getline(cin,name);
		cout<<"Enter your age: ";
		cin>>age;
	}
	friend class display;
};
class display
{ 
public:
	void show(student s1)
	{
        cout<<endl<<"---------(Details You Enterd)---------"<<endl;
		cout<<"Name: "<<s1.name<<endl;
		cout<<"Age: "<<s1.age<<endl;
	}
};
int main()
{
	student s;
	display  d1;
	d1.show(s);
}