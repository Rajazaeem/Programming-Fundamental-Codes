#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

class Student {
private:
    char name[50];   // Array for student name
    int grades[5];   // Array for grades
    int gradeCount;  // Tracks the number of grades

public:
    // Default Constructor
    Student() : gradeCount(0) {
        name[0] = '\0'; // Set name to an empty string
    }

    // Parameterized Constructor
    Student(const char* studentName) : gradeCount(0) {
        strncpy(name, studentName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Ensure null termination
    }

    // Add grade function
    void addGrade(int grade) {
        if (gradeCount < 5) {
            if (grade >= 0 && grade <= 100) {
                grades[gradeCount++] = grade;
            } else {
                cout << "Error: Grade " << grade << " invalid (must be 0-100)." << endl;
            }
        } else {
            cout << "You Cannot add more grades. Grade array is full." << endl;
        }
    }

    // Print record function
    void printRecord() const {
        cout << "Student Name: " << name << " - Grades: [";
        for (int i = 0; i < gradeCount; ++i) {
            cout << grades[i];
            if (i < gradeCount - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    // Function to take user input for grades
    void inputGrades() {
        cout << "Enter grades for " << name << " (up to 5 grades). Type -1 to stop." << endl;
        int grade;
        while (gradeCount < 5) {
            cout << "Enter grade #" << (gradeCount + 1) << ": ";
            while (true) {
                cin >> grade;

                // Check for valid input
                if (cin.fail()) {
                    cin.clear(); // Clear error state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. Please enter a valid integer." << endl;
                } else {
                    // Allow user to stop input by entering -1
                    if (grade == -1) {
                        return; // Stop input if -1 is entered
                    }
                    // Validate the grade range
                    if (grade >= 0 && grade <= 100) {
                        addGrade(grade); // Add the entered grade
                        break;  // Exit loop for valid input
                    } else {
                        cout << "Error: Grade " << grade << " invalid (must be 0-100)." << endl;
                    }
                }
            }
        }
    }

    // Function to validate the name
    bool isValidName(const char* studentName) {
        return (strlen(studentName) > 0 && strlen(studentName) < sizeof(name));
    }
};

int main() {
    char studentName[50];

    // Input with user feedback and validation
    Student student; // Create student object first

    while (true) {
        cout << "Enter student's name (must be non-empty and max 49 characters): ";
        cin.getline(studentName, sizeof(studentName)); // Read name including spaces

        // Validate name length and content
        if (!student.isValidName(studentName)) {
            cout << "Error: Invalid name! Please enter a valid name (non-empty)." << endl;
        } else {
            student = Student(studentName); // Update the existing student object
            student.inputGrades(); // Take user input for grades
            break; // Exit loop if name and grades are valid
        }
    }

    // Print the record for the student
    cout << "Student Record:" << endl;
    student.printRecord();

    // Copy the student to a new student
    Student s2 = student; // Copying the student to s2
    s2.addGrade(95); // Adding additional grade to s2

    cout << "Copied Record (s2): ";
    s2.printRecord(); // Should show updated grades for s2
    cout << "Original Record (student): ";
    student.printRecord(); // Should show the original student grades

    return 0;
}