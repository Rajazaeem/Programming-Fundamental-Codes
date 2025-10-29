#include <iostream>
#include <string>
using namespace std;

// Base Class: Person
class Person {
protected:
    string name;
    string CNIC;
    string mobileNumber;
    static int personCount; // Static counter

public:
    Person(string n, string cnic, string mobile) {
        name = n;
        CNIC = cnic; 
        mobileNumber = mobile;
        personCount++;
    }

    static int getPersonCount() {
        return personCount;
    }

    void showBasicInfo() const {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Mobile: " << mobileNumber << endl;
    }
};

// Initialize static member
int Person::personCount = 0;

// Independent Class: AdministrativeRole
class AdministrativeRole {
protected:
    string roleTitle;
    string officeNumber;

public:
    AdministrativeRole(string title, string office) {
        roleTitle =title;
        officeNumber=office;
    }

    void showAdminDetails() const {
        cout << "Administrative Role: " << roleTitle << endl;
        cout << "Office Number: " << officeNumber << endl;
    }
};

// Independent Class: AcademicSupportRole
class AcademicSupportRole {
protected:
    string subjectAssisted;
    int labHours;

public:
    AcademicSupportRole(string subject, int hours) {
        subjectAssisted = subject;
        labHours = hours;
    }

    void showAcademicDetails() const {
        cout << "Subject Assisted: " << subjectAssisted << endl;
        cout << "Lab Hours: " << labHours << endl;
    }
};

// Derived Class: SupportStaff (Multiple + Hybrid Inheritance)
class SupportStaff : public Person, public AdministrativeRole, public AcademicSupportRole {
private:
    string shiftTiming;
    string supervisorName;

public:
    SupportStaff(string n, string cnic, string mobile,
                 string title, string office,
                 string subject, int hours,
                 string shift, string supervisor)
        : Person(n, cnic, mobile),
          AdministrativeRole(title, office),
          AcademicSupportRole(subject, hours) {
              shiftTiming = shift;
              supervisorName = supervisor;
          }

    void displayFullProfile() const {
        cout << "-------- Support Staff Profile --------" << endl;
        showBasicInfo();
        showAdminDetails();
        showAcademicDetails();
        cout << "Shift Timing: " << shiftTiming << endl;
        cout << "Supervisor: " << supervisorName << endl;
        cout << "---------------------------------------" << endl;
    }
};

// Main Function
int main() {
    SupportStaff staff[3] = {
        SupportStaff("Ali Khan", "35202-1234567-1", "03001234567",
                     "Clerk", "Admin Block A1", "Physics", 10, "Morning", "Dr. Farooq"),

        SupportStaff("Sara Ahmed", "35202-7654321-2", "03111234567",
                     "Receptionist", "Admin Block B2", "Math", 8, "Evening", "Dr. Nida"),

        SupportStaff("Hamza Tariq", "35202-1111222-3", "03221234567",
                     "Assistant", "Admin Block C3", "Computer", 12, "Afternoon", "Dr. Bilal")
    };

    for (int i = 0; i < 3; i++) {
        staff[i].displayFullProfile();
    }

    cout << "Total number of people created: " << Person::getPersonCount() << endl;

    return 0;
}