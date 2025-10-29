#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

// Function to sort a column in 2D array
void sortcolumn(double matrix[3][3], int col)
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            if (matrix[i][col] > matrix[j][col])
            {
                // swap the elements
                double temp = matrix[i][col];
                matrix[i][col] = matrix[j][col];
                matrix[j][col] = temp;
            }
        }
    }
}

// Function to safely input a double value
bool safeInput(double &value)
{
    cin >> value;
    if (cin.fail()) // checks if input is not a valid double
    {
        cin.clear();                                         // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input! Please enter a valid number." << endl;
        return false;
    }
    return true;
}

int main()
{
    // declare a 3x3 matrix
    double matrix[3][3];

    // Ask user to enter 3x3 matrix
    cout << "Enter 3x3 matrix row by row:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            while (!safeInput(matrix[i][j]))
            {
                cout << "Please enter a valid number for matrix[" << i << "][" << j << "]: ";
            }
        }
    }

    // sort each column of matrix
    for (int col = 0; col < 3; ++col)
    {
        sortcolumn(matrix, col);
    }

    // save the sorted matrix to file
    ofstream outputFile("sorted_matrix.txt");
    if (!outputFile)
    {
        cout << "Error: Unable to open file for watching." << endl;
        return 1;
    }

    // write the second matrix to the file and display
    cout << "\nThe column-sorted matrix is:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            outputFile << matrix[i][j] << " ";
            cout << matrix[i][j] << " ";
        }
        outputFile << endl;
        cout << endl;
    }
    outputFile.close();
    cout << "The sorted matrix has been safe to 'stored-matrix.txt'" << endl;
    return 0;
}