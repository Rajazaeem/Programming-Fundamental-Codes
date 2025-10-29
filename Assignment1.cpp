#include <iostream>
#include <string>

using namespace std;
// making a structure..
struct student
{
    string Name;
    int Roll_no;
    float marks;
};

int main()
{
    student s;
    // Making a object of a structure
    cout << "Enter the name of the student: ";
    getline(cin, s.Name);
    cout << "Enter the Roll no of a student :";
    cin >> s.Roll_no;
    cout << "Enter the marks of a student :";
    cin >> s.marks;

    cout << "\nDetails you entered" << endl;
    cout << "\nName of student is: " << s.Name
         << "\nRoll no of a student is: " << s.Roll_no
         << "\nMarks of a student is: " << s.marks;
    return 0;
}