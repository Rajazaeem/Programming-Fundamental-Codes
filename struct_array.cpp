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
void display(student s1[], int max)
{
    for (int i = 0; i < max; i++)
    {
        cout << endl;
        cout << "Name: " << s1[i].name << endl;
        cout << "Roll No: " << s1[i].roll_no << endl;
        cout << "Zip code: " << s1[i].add.zip_code << endl;
        cout << "Adderss: " << s1[i].add.address << endl;
        cout << endl;
    }
}

int main()
{
    const int MAX_student = 3;
    student s[MAX_student];
    for (int i = 0; i < MAX_student; i++)
    {
        cout << "Enter the details olf student " << i + 1 << endl;
        cout << "Enter the name of student: ";
        cin.ignore();
        getline(cin, s[i].name);
        cout << "Enter the roll number of student: ";
        cin >> s[i].roll_no;
        cout << "Enter the zip code of student: ";
        cin >> s[i].add.zip_code;
        cout << "Enter the address of student: ";
        cin.ignore();
        getline(cin, s[i].add.address);
        cout << endl;
    }
    display(s, MAX_student);
    return 0;
}