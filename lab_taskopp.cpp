#include <iostream>
#include <string>
using namespace std;

class students {
    string name;
    int roll_no;
    int age;

public:
    students(string n, int rn,int a) {
        name = n;
        roll_no= rn;
        age =a;
    }
    string getName()
	 { 
	 return name;
	  }
    int getage()
	 { 
	 return age;
	  }
    int getroll_No()
	 { 
	 return roll_no;
	  }

    
};

void show(students s) {
    cout << s.getName() << endl;
    cout << s.getage() << endl;
    cout << s.getroll_No() << endl;
}

int main() {
    string n; 
    int rn, a;
    cout <<"Enter your name: ";
    getline(cin,n);
    cout <<"Enter your roll no: ";
    cin>>rn;
    cout <<"Enter your age: ";
    cin>>a;
    students s1(n,rn,a);
    cout<<"\n--------Details You Enterd---------\n"<<endl;
    show(s1); 
    return 0;
}
