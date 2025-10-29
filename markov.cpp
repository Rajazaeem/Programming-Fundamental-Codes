#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

// function for error handling
bool safeInput(double &value)
{
    cin >> value;
    if (cin.fail())
    {                                                        // check if number is not valid
        cin.clear();                                         // clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input! Please enter a valid number." << endl;
        return false;
    }
    return true;
}

int main()
{
    string runAgain;
    do
    {
        double matrix[3][3];
        bool isMarkov = true; // To track weather the matrix is a Markov matrix

        // Ask user to input a 3x3 matrix row by row
        cout << "Enter a 3x3 matrix row by row:" << endl;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                while (!safeInput(matrix[i][j]))
                { // keep asking for a valid input
                    cout << "Please enter a valid numberfor matrix[" << i << "][" << j << "]: ";
                }
            }
        }
        // check all elements are possitive (greater than 0)
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (matrix[i][j] <= 0)
                {
                    isMarkov = false; // if any element is nonpossitive,it's not a Markovmatrix
                    break;            // No need to check further if we already found a non-possitive element
                }
            }
        }

        // check if the sum of each column is 1
        for (int j = 0; j < 3; ++j)
        {
            double columnSum = 0;
            for (int i = 0; i < 3; ++i)
            {
                columnSum += matrix[i][j]; // sum the value of column
            }
            if (columnSum != 1.0)
            {
                isMarkov = false; // If the sum of column is n ot 1, it's not a Markov matrix
                break;            // No need to check other column if one already fails
            }
        }

        // output the result to a file
        ofstream outputFile("matrix_output.txt");

        if (outputFile)
        {
            if (isMarkov)
            {
                cout << "It is Markov matrix" << endl;
                outputFile << "It is Markov matrix" << endl;
            }
            else
            {
                cout << "It is not a Markov matrix" << endl;
                outputFile << "It is not a Markov matrix" << endl;
            }
            outputFile.close(); // close the file afterwriting
            cout << "The result has been written to(matrix_output.txt)" << endl;
        }
        else
        {
            cout << "Erroe: Unable to open the file to write the output." << endl;
        }
        // Ask the user if they want to run the program again
        cout << "Do you want to run again? (yes/no): ";
        cin >> runAgain;
    } while (runAgain == "yes" || runAgain == "Yes"); // Repeate if user enter yes or Yes
    cout << "Thanks you for using the program!" << endl;
    return 0;
}