#include <iostream>
using namespace std;
struct date_of_birth
{
	int dd, mm, yyyy;
};
struct student
{
    int roll_number;
    char name[30];
    date_of_birth dob;
};
int main()
{
	student S1;
	cout << "Enter Name of Student: ";
	cin.getline( S1.name, 25);
	cout << "Enter Roll Number of Student: ";
	cin >> S1.roll_number;
	cout << "Enter Date of Birth (dd-mm-yyyy): ";
	cin >> S1.dob.dd >> S1.dob.mm >> S1.dob.yyyy;
	
	cout << "\nName: " << S1.name << endl;
	cout << "Roll Number: " << S1.roll_number << endl;
	cout << "Date of Birth: " << S1.dob.dd << "" << S1.dob.mm << "" << S1.dob.yyyy ;
	
	return 0;
}
