#include<iostream>
#include<string>
using namespace std;


class item
{
    private:
    string name;
    float price;
    int quantity;
    
	public:
	void input()
	{
		cout<<"Enter item name: ";
		getline(cin,name);
		cout<<"Enter the price of the item: ";
        cin>>price;
		cout<<"Enter quantity: ";
		cin>>quantity;
	}

	friend class calculate;
	friend void display(item i1);
};

class calculate
{ 
public:
	float bill(item i1)
	{
		float total;
		total=i1.price * i1.quantity;
		return total;
	}

 	friend void display(item i1);
};

void display(item i1)
{
	float total;
    cout<<endl<<"------(Item Details)------"<<endl;
	cout<<"Name: "<<i1.name<<endl;
	cout<<"Price: "<<i1.price<<endl;
	cout<<"Quantity: "<<i1.quantity<<endl;
}

int main()
{
	item i;
	calculate c1;
	i.input();
	c1.bill(i);
	display(i);
}