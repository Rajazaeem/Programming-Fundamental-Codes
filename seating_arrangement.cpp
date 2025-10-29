#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// Function to print the seating arrangement
void printSeating(int seats[10][15], ofstream &outputFile)
{
    outputFile << "Updated seating Arrangement:" << endl;
    cout << "Updated seating Arrangement:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 15; ++j)
        {
            cout << seats[i][j] << " ";
            outputFile << seats[i][j] << " ";
        }
        cout << endl;
        outputFile << endl;
    }
}

// Function to find closest seat to the middle of a row
int findClosestSeat(int row[15])
{
    int mid = 7; // middle seat in a o-index array of 15 (index 7 is the middle seat)
    int closestSeat = mid;

    // Check from the middle seat outwords to find the first available seat
    for (int i = 0; i < 8; ++i)
    {
        if (closestSeat - i >= 0 && row[closestSeat - i == 0])
        {
            return closestSeat - i;
        }
        if (closestSeat + i < 15 && row[closestSeat + i] == 0)
        {
            return closestSeat + i;
        }
    }
    return -1; // Return -1 if no seat is available
}

int main()
{
    // Initializing the seating arrangement:0=available,1 = reserved
    int seats[10][15] = {
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, // Row 1
        {1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0}, // Row 2
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0}, // Row 3
        {0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0}, // Row 4
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0}, // Row 5
        {0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0}, // Row 6
        {1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1}, // Row 7
        {0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0}, // Row 8
        {0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0}, // Row 9
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0}  // Row 10
    };

    // File output handling
    ofstream outputFile("seating_arrangement.txt");
    if (!outputFile)
    {
        cout << "Error: Could not open the file for writing." << endl;
        return 1;
    }
    int rowNumber;
    cout << "Enter a desire row number (1-10): ";

    // Loop until valid input is given for row number
    while (true)
    {
        cin >> rowNumber;

        // Error handling for invalid row input
        if (cin.fail() || rowNumber < 1 || rowNumber > 10)
        {
            cin.clear(); // clear the error flage
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid row number. Please enter a row number between 1 and 10: ";
        }
        else
        {
            break; // Break out of the loop once valid input recived
        }
    }
    // Find closest seat to the middle of the row (index 0-14)
    int rowIndex = rowNumber - 1; // convert to 0-index row
    int seatIndex = findClosestSeat(seats[rowIndex]);

    if (seatIndex == -1)
    {
        cout << "No available seat in row " << rowNumber << endl;
        outputFile << "No available seat in row " << rowNumber << endl;
    }
    else
    {
        cout << "The closest available seat in row " << rowNumber << " is seat " << (seatIndex + 1) << endl;
        outputFile << "The closest available seat in row " << rowNumber << " is seat " << (seatIndex + 1) << endl;

        // Mark the seat as reserved
        seats[rowIndex][seatIndex] = 1;
    }
    printSeating(seats, outputFile);

    // close the file
    outputFile.close();

    cout << "Updated seating arrangement has been written to (seating_arrangement.txt)" << endl;
    return 0;
}