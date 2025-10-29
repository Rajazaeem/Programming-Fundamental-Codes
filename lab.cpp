#include<iostream>
#include<string>

using namespace std;
class student{
    private:
    string name;
    int age;
    public:
    student(){
        name="unknown";
        age=0;
    }
   
    student(string n, int a){
        this->name =n;
        this->age =a;

    }
    student (student& s2){
        name = s2.name;
        age = s2.age;
    }
    void display(){
        cout <<"Name of a student is: "<<this->name<<endl;
        cout <<"Age of a student is: "<<this->age<<endl;
    }
    ~student (){
        cout <<"Distructor is called"<<endl;
    }
};

int main(){
    student s("ali",20);
    s.display();
    student s1(s);
    s1.display();

    cout<<endl<<"Here S1 is changed"<<endl;

    return 0;
    

}