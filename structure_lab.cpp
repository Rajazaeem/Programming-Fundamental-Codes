#include <iostream>
#include <string>

using namespace std;

struct address
{
    int zip_code;
    string address;
};

struct student
{
    string name;
    int roll_no;
    address add;
};
void display(student s1)
{
    cout << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Roll No: " << s1.roll_no << endl;
    cout << "Zip code: " << s1.add.zip_code << endl;
    cout << "Adderss: " << s1.add.address << endl;
}

int main()
{
    student s;
    cout << "Enter the details olf student " << endl;
    cout << "Enter the name of student: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter the roll number of student: ";
    cin >> s.roll_no;
    cout << "Enter the zip code of student: ";
    cin >> s.add.zip_code;
    cout << "Enter the address of student: ";
    cin.ignore();
    getline(cin, s.add.address);
    display(s);
    return 0;
}