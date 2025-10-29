#include <iostream>
#include <string>

using namespace std;

class student{
    private:
    string name;
    int age;
    float marks;
    public:
    student(){}
    void set_value(string name,int age,float marks){
        this->name =name;
        this->age =age;
        this->marks =marks;
    }
    friend void Student_details(student& s);

};

void Student_details(student& s) {
    cout <<"The name of student is: "<<s.name<<endl;
    cout <<"The age of a student is: "<<s.age<<endl;
    cout <<"The marks of the student is: "<<s.marks<<endl;
}

int main(){
    student s1; 
    s1.set_value("Zaeem",20,49); 
    Student_details(s1);
return 0;
}