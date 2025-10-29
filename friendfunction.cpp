#include <iostream>
#include <string>

using namespace std;

class solutions {
private:
    string name;
    int age;
    float rollno;

public:
    // Default constructor
    solutions() {}

    // Parameterized constructor (optional usage)
    solutions(string name, int age, float rollno) {
        this->name = name;
        this->age = age;
        this->rollno = rollno;
    }

    // Setter method to set details
    void setDetails(const string& name, int age, float rollno) {
        this->name = name;
        this->age = age;
        this->rollno = rollno;
    }

    // Function to print the student's details
    friend void print(solutions f)  {
        cout << "Name: " << f.name << endl;
        cout << "Age: " << f.age << endl;
        cout << "Roll No: " << f.rollno << endl;
    }
};

int main() {
    const int MAX_NUM = 100;
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    // Validate number of students input
    if (n > MAX_NUM || n <= 0) {
        cout << "Please enter a valid number of students (1 to " << MAX_NUM << ")." << endl;
        return 1; // Exit with an error code
    }

    solutions s[MAX_NUM]; // Array of student objects

    cin.ignore(); // Clear the newline character from the input buffer

    for (int i = 0; i < n; i++) {
        string name;
        int age;
        float rollno;

        cout << "Enter the name of student " << i + 1 << ": ";
        getline(cin, name); // Get name input

        cout << "Enter the age of student " << i + 1 << ": ";
        cin >> age;

        cout << "Enter the roll number of student " << i + 1 << ": ";
        cin >> rollno;

        cin.ignore(); // Clear the newline character for the next input

        // Use setDetails to assign the values
        s[i].setDetails(name, age, rollno);
    }

    // Print the details of each student
    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Details of student " << i + 1 << ":\n";
        print(s[i]); // Call the print function to display student details
    }

    return 0;
}