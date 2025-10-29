#include <iostream>
using namespace std;
struct student
{
    int stu_IDN;
    string stu_name;
    string AttP;
    string MarksP;
    char grade[5];
};
void Display (student);
int main()
{
	student S1;
	cout << "Enter ID of Student: ";
	cin >> S1.stu_IDN;
	cout << "Enter Name of Student: ";
	cin >> S1.stu_name;
	cout << "Enter Attendance Percentage: ";
	cin >> S1.AttP;
	cout << "Enter Marks Percentage: ";
	cin >> S1.MarksP;
	cout << "Enter Grade: ";
	cin >> S1.grade;
	
	Display (S1);
	return 0;
}
void Display (student S1)
{
	cout << "\nDisplaying Information of Student." << endl;
	cout << "ID: " << S1.stu_IDN << endl;
	cout << "Name: " << S1.stu_name << endl;
	cout << "Attendance %: " << S1.AttP << endl;
	cout << "Marks %: " << S1.MarksP << endl;
	cout << "Grade: " << S1.grade << endl;
}