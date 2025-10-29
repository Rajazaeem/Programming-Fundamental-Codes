#include <iostream>
#include <fstream> // Include the fstream library to handle file operations
using namespace std;

int scores[100]; // an integer array of 100 elements

float findAverage(int); // finds average of all grades
int findHighest(int);   // finds highest of all grades
int findLowest(int);    // finds lowest of all grades

int main()
{
    int numberOfGrades; // the number of grades read.
    int pos;            // index to the array element.

    float avgOfGrades; // contains the average of the grades.
    int highestGrade;  // contains the highest grade.
    int lowestGrade;   // contains the lowest grade.

    ifstream inFile("gradfile.txt"); // Open the file for reading

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1; // Exit the program if the file can't be opened
    }

    // Read in the values into the array from the file
    pos = 0;
    while (inFile >> scores[pos] && pos < 100) { // Read the scores into the array
        pos++;
    }

    numberOfGrades = pos; // set the number of grades read

    // Display the grades read from the file
    cout << "The grades read from the file are:" << endl;
    for (int i = 0; i < numberOfGrades; i++) {
        cout << scores[i] << "\n ";
    }
    cout << endl;

    // Call to the function to find average
    avgOfGrades = findAverage(numberOfGrades);
    cout << endl << "The average of all the scores is " << avgOfGrades << endl;

    // Call to the function that calculates highest grade
    highestGrade = findHighest(numberOfGrades);
    cout << endl << "The highest grade is " << highestGrade << endl;

    // Call to the function that calculates lowest grade
    lowestGrade = findLowest(numberOfGrades);
    cout << endl << "The lowest grade is " << lowestGrade << endl;

    inFile.close(); // Close the file after reading

    return 0;
}

//********************************************************************************
// findAverage
//
// task: This function receives size as the number of elements in the globally defined array.
// It finds and returns the average of the numbers in the array.
// data in: number as size
// data returned: average of the numbers in the array
//
//********************************************************************************
float findAverage(int size)
{
    float sum = 0; // holds the sum of all the numbers

    for (int i = 0; i < size; i++)
        sum += scores[i];

    return (sum / size); // returns the average
}

//****************************************************************************
// findHighest
//
// task: This function receives size as the number of elements in the globally defined array.
// It finds and returns the highest value of the numbers in the array.
// data in: number
// data returned: highest value of the numbers in the array
//
//****************************************************************************
int findHighest(int size)
{
    int highest = scores[0]; // start with the first score

    for (int i = 1; i < size; i++)
    {
        if (scores[i] > highest)
        {
            highest = scores[i];
        }
    }
    return highest;
}

//****************************************************************************
// findLowest
//
// task: This function receives size as the number of elements in the globally defined array.
// It finds and returns the lowest value of the numbers in the array.
// data in: number
// data returned: lowest value of the numbers in the array
//
//****************************************************************************
int findLowest(int size)
{
    int lowest = scores[0]; // start with the first score

    for (int i = 1; i < size; i++)
    {
        if (scores[i] < lowest)
        {
            lowest = scores[i];
        }
    }
    return lowest;
}
