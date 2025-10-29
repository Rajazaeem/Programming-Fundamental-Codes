#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        string name;
        int roll_number;
        float marks;

    public:
        // Default constructor
        Student() {}
        // Function to set student details
        void setDetails(string name, int roll_number, float marks) {
           this->name = name;
            this->roll_number = roll_number;
            this->marks = marks;
        }

        // Friend function declaration
        friend void generateReport(const Student& s);
};

// Friend function to generate and display the student report
void generateReport(const Student& s) {
    cout << "----- Student Report -----" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.roll_number << endl;
    cout << "Marks: " << s.marks << endl;
    cout << "--------------------------" << endl;
}

int main() {
    
    // Create a Student object and set its details
    Student s1;
    s1.setDetails("zaeem",247169,88);
   

    // Generate and display the student's report
    generateReport(s1);

    return 0;
}