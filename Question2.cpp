#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct student
{
    string name;
    int roll_no;
    float marks;
};
//Making a function 
void Display(student s2);
int main()
{
    student s;
    // Making a object of a structure
    cout << "Enter the name of the student: ";
    getline(cin, s.name);
    cout << "Enter the Roll no of a student :";
    cin.ignore();
    cin >> s.roll_no;
    cout << "Enter the marks of a student :";
    cin >> s.marks;
    //function call
    Display(s);

    return 0;
}
//Display the output through the function
void Display(student s2)
{
    cout << "\nDetails you entered" << endl;
    cout << "\nName of student is: " << s2.name
         << "\nRoll no of a student is: " << s2.roll_no
         << fixed << setprecision(2)
         << "\nMarks of a student is: " << s2.marks;
}