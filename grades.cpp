#include <iostream>
using namespace std;

const int MAX_GRADES = 50; // Maximum number of grades

// Function prototype
int countGrades(const char grades[], int numGrades, char gradeCategory);

int main() {
    char grades[MAX_GRADES]; // Array to store grades
    int numGrades;           // Number of grades to input

    // Prompt the user for the number of grades
    cout << "Enter the number of grades (maximum " << MAX_GRADES << "): ";
    cin >> numGrades;

    // Validate the input
    while (numGrades < 1 || numGrades > MAX_GRADES) {
        cout << "Invalid number. Please enter a value between 1 and " << MAX_GRADES << ": ";
        cin >> numGrades;
    }

    // Input the grades
    cout << "Enter the grades (A, B, C, D, F):" << endl;
    for (int i = 0; i < numGrades; i++) {
        cin >> grades[i];
        // Validate the grade input
        while (grades[i] != 'A' && grades[i] != 'B' && grades[i] != 'C' &&
               grades[i] != 'D' && grades[i] != 'F') {
            cout << "Invalid grade. Please enter A, B, C, D, or F: ";
            cin >> grades[i];
        }
    }

    // Output the count for each grade category
    cout << "Grade counts:" << endl;
    cout << "A: " << countGrades(grades, numGrades, 'A') << endl;
    cout << "B: " << countGrades(grades, numGrades, 'B') << endl;
    cout << "C: " << countGrades(grades, numGrades, 'C') << endl;
    cout << "D: " << countGrades(grades, numGrades, 'D') << endl;
    cout << "F: " << countGrades(grades, numGrades, 'F') << endl;

    return 0;
}

//***********************************************************************
// countGrades
//
// task: This function counts the number of grades in a specific category.
//
// data in: array of grades, number of grades, and grade category
// data returned: count of grades in the specified category
//
//***********************************************************************
int countGrades(const char grades[], int numGrades, char gradeCategory) {
    int count = 0;
    for (int i = 0; i < numGrades; i++) {
        if (grades[i] == gradeCategory) {
            count++;
        }
    }
    return count;
}