#include <iostream>
#include <string>

using namespace std;

class person
{
protected:
    string name;
    string cnic;
    string mombile_no;
    static int person_count;
    string country_code;

public:
    person() {}
    person(string n, string nic, string cell)
    {
        name = n;
        cnic = nic;
        mombile_no = cell;
        country_code = "+92";
        person_count++;
        cout << "Constructor Called for (employee): " << name << endl;
    }
    ~person()
    {
        cout << "Destructor call of (employee): " << name << "\n";
    }

    static int personcount()
    {
        return person_count;
    }
    inline void display_info()
    {
        cout << "Name: " << name << "\nCNIC: " << cnic
             << "\nMobile: " << country_code << "-" << mombile_no << endl;
    }
};

int person::person_count = 0;

class employee : public person
{
protected:
    string employeeID;
    string designation, department;

public:
    employee() {}
    employee(string n, string nic, string cell, string employeeID, string designation, string department) : person(n, nic, cell)
    {

        this->employeeID = employeeID;
        this->designation = designation;
        this->department = department;
        cout << "Constructor Called for (employee): " << name << endl;
    }
    ~employee()
    {
        cout << "Destructor call of (employee): " << name << "\n";
    }

    inline void display_info()
    {
        person::display_info();
        cout << "Employee ID is: " << employeeID
             << "\nDesignation is: " << designation
             << "\nDepartment is: " << department;
    }
};
class TechnicalStaff : public employee
{
private:
    string areaOfExpertise, machineAllocated;

public:
    TechnicalStaff() {}
    TechnicalStaff(string n, string nic, string cell, string employeeID, string designation, string department, string areaOfExpertise, string machineAllocated)
        : employee(n, nic, cell, employeeID, designation, department)
    {
        this->areaOfExpertise = areaOfExpertise;
        this->machineAllocated = machineAllocated;
        cout << "Constructor Called for (employee): " << name << endl;
    }
    ~TechnicalStaff()
    {
        cout << "Destructor call for (employee): " << name << "\n";
    }
    void showstate()
    {
        this->display_info();
        cout << "Employee Area: " << this->areaOfExpertise << endl
             << "Machine Allocated: " << this->machineAllocated;
    }
};
int main()
{
    const int number_staff = 3;
    TechnicalStaff t[number_staff] = {
        TechnicalStaff("Ali Raza", "35201 - 1234567 - 1", "3001234567", "EMP247111", "Engineer", "IT", "Networking", "Router A1"),
        TechnicalStaff("Sara Khan", "35202 - 7654321 - 2", "3007654321", "EMP247112", "programmer", "programming", "Circuits", "Oscilloscope B2"),
        TechnicalStaff("Ahmed Iqbal", "35203 - 9876543 - 3", "3009876543", "EMP247113", "Security expert", "Cyber Security", "AI/ML", "Server ABC")};
    cout << "\n\n=================Desplay staff information======================\n\n";
    for (int i = 0; i < number_staff; i++)
    {
        t[i].showstate();
        cout << "\n\n********************************************************\n\n";
    }
    cout << "\n========================================================\n";
    cout << "Total person: " << person::personcount() << endl;

    return 0;
}