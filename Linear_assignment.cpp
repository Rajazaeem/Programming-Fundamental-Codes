                                  /* Members Names 
                                  Usama Arshad
                                  M.Hamza Ali
                                  Zaeem Furqan
                                  Asad Farooq*/


#include <iostream>
#include <cmath>
#include <limits> // Include for numeric_limits

#ifndef M_PI
#define M_PI 3.14159265358979323846 // For defining the PI 
#endif

using namespace std;

// Function to input and validate a 2D vector
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

void input2D(double matrix[2])
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true)
    {
        cout << "Enter the 2D vector (2x1 matrix): ";

        string line;
        getline(cin, line);   // Read entire line of input

        stringstream ss(line);
        double val1, val2;
        double extra;
        
        if (ss >> val1 >> val2)  // Successfully read two numbers
        {
            if (ss >> extra)
            {
                cout << "Error: Extra entries detected. Only the first two numbers will be used.\n";
            }

            matrix[0] = val1;
            matrix[1] = val2;
            break;  // Valid input collected
        }
        else
        {
            cout << "Invalid input! Please enter exactly two numeric values.\n";
        }
    }
}

// Function to input and validate a 3D vector
void input3D(double matrix[3])
{
    // Flush any leftover input (in case of previous cin >>)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true)
    {
        cout << "Enter the 3D vector (3x1 matrix): ";

        string line;
        getline(cin, line);   // Read entire line of input

        stringstream ss(line);
        double val1, val2, val3;
        double extra;

        if (ss >> val1 >> val2 >> val3)  // Successfully read three numbers
        {
            if (ss >> extra)
            {
                cout << "Error: Extra entries detected. Only the first three numbers will be used.\n";
            }

            matrix[0] = val1;
            matrix[1] = val2;
            matrix[2] = val3;
            break;  // Valid input collected
        }
        else
        {
            cout << "Invalid input! Please enter exactly three numeric values.\n";
        }
    }
}

// Function for 2D transformations
void solve_2D()
{
    double matrix[2]; // Vector in R^2
    double ans[2];    // Resultant vector

    input2D(matrix); // Input 2D vector

    while (true)
    {
        int c;

        cout << "Select the type of transformation: " << endl;
        cout << "1. Projection onto the x-axis" << endl
             << "2. Projection onto the y-axis" << endl
             << "3. Expansion" << endl
             << "4. Dilation" << endl
             << "5. Shear" << endl
             << "6. Rotation" << endl;

        cout << "Enter your choice: ";
        cin >> c;

        switch (c)
        {
        case 1: // Projection onto x-axis
            // Standard matrix for projection onto x-axis
            ans[0] = matrix[0]; // 1 * x + 0 * y
            ans[1] = 0;         // 0 * x + 0 * y
            break;

        case 2: // Projection onto y-axis
            // Standard matrix for projection onto y-axis
            ans[0] = 0;         // 0 * x + 0 * y
            ans[1] = matrix[1]; // 0 * x + 1 * y
            break;

        case 3: // Expansion
        {
            char dir;
            do
            {
                cout << "Perform vertical (v) or horizontal (h) expansion? (v/h): ";
                cin >> dir;
                if (dir != 'v' && dir != 'h')
                {
                    cout << "Invalid choice! Please enter 'v' for vertical or 'h' for horizontal." << endl;
                }
            } while (dir != 'v' && dir != 'h');

            double k;
            do
            {
                cout << "Enter expansion factor (k > 1): ";
                cin >> k;
                if (k <= 1)
                {
                    cout << "Invalid factor! Please enter a number greater than 1." << endl;
                }
            } while (k <= 1);

            if (dir == 'v')
            {
                // Standard matrix for vertical expansion
                ans[0] = matrix[0];       // 1 * x + 0 * y
                ans[1] = k * matrix[1];   // 0 * x + k * y
            }
            else // horizontal
            {
                // Standard matrix for horizontal expansion
                ans[0] = k * matrix[0];   // k * x + 0 * y
                ans[1] = matrix[1];       // 0 * x + 1 * y
            }
            break;
        }

        case 4: // Dilation
        {
            char dir;
            do
            {
                cout << "Perform vertical (v) or horizontal (h) dilation? (v/h): ";
                cin >> dir;
                if (dir != 'v' && dir != 'h')
                {
                    cout << "Invalid choice! Please enter 'v' for vertical or 'h' for horizontal." << endl;
                }
            } while (dir != 'v' && dir != 'h');

            double k;
            do
            {
                cout << "Enter dilation factor (0 < k < 1): ";
                cin >> k;
                if (k <= 0 || k >= 1)
                {
                    cout << "Invalid factor! Please enter a number greater than 0 and less than 1." << endl;
                }
            } while (k <= 0 || k >= 1);

            if (dir == 'v')
            {
                // Standard matrix for vertical dilation
                ans[0] = matrix[0];       // 1 * x + 0 * y
                ans[1] = k * matrix[1];   // 0 * x + k * y
            }
            else // horizontal
            {
                // Standard matrix for horizontal dilation
                ans[0] = k * matrix[0];   // k * x + 0 * y
                ans[1] = matrix[1];       // 0 * x + 1 * y
            }
            break;
        }

        case 5: // Shear
        {
            char dir;
            do
            {
                cout << "Perform vertical (v) or horizontal (h) shear? (v/h): ";
                cin >> dir;
                if (dir != 'v' && dir != 'h')
                {
                    cout << "Invalid choice! Please enter 'v' for vertical or 'h' for horizontal." << endl;
                }
            } while (dir != 'v' && dir != 'h');

            double k;
            cout << "Enter shear factor (k): ";
            cin >> k;

            if (dir == 'v')
            {
                // Standard matrix for vertical shear
                ans[0] = matrix[0] + k * matrix[1]; // Shear in x-direction
                ans[1] = matrix[1];                  // No change in y
            }
            else // horizontal
            {
                // Standard matrix for horizontal shear
                ans[0] = matrix[0];                  // No change in x
                ans[1] = matrix[1] + k * matrix[0]; // Shear in y-direction
            }
            break;
        }

        case 6: // Rotation
        {
            double angle;
            cout << "Enter rotation angle in degrees: ";
            cin >> angle;
            double radians = angle * (M_PI / 180.0); // Convert to radians

            // Standard matrix for rotation
            ans[0] = cos(radians) * matrix[0] - sin(radians) * matrix[1];
            ans[1] = sin(radians) * matrix[0] + cos(radians) * matrix[1];
            break;
        }

        default:
            cout << "Invalid choice! Please select a valid transformation." << endl;
            continue; // Restart the loop for valid input
        }

        cout << "Transformed vector: (" << ans[0] << ", " << ans[1] << ")" << endl;

        char choice;
        cout << "Do you want to further transform the current vector (y/n)? ";
        cin >> choice;
        if (choice == 'n')
        {
            cout << "Do you want to input a new vector (y/n)? ";
            cin >> choice;
            if (choice == 'y')
            {
                input2D(matrix); // Input new 2D vector
            }
            else
            {
                cout << "Exiting to main menu." << endl;
                break; // Exit to main menu
            }
        }
    }
}

// Function for 3D transformations
void solve_3D()
{
    double matrix[3]; // Vector in R^3
    double ans[3];    // Resultant vector

    input3D(matrix); // Input 3D vector

    while (true)
    {
        int c;

        cout << "Select the type of transformation: " << endl;
        cout << "1. Projection onto the xy-plane" << endl
             << "2. Projection onto the xz-plane" << endl
             << "3. Projection onto the yz-plane" << endl
             << "4. Reflection about the xy-plane" << endl
             << "5. Reflection about the xz-plane" << endl
             << "6. Reflection about the yz-plane" << endl;

        cout << "Enter your choice: ";
        cin >> c;

        switch (c)
        {
        case 1: // Projection onto xy-plane
            // Standard matrix for projection onto xy-plane
            ans[0] = matrix[0]; ans[1] = matrix[1]; // y remains the same
            ans[2] = 0;         // z is set to 0
            break;

        case 2: // Projection onto xz-plane
            // Standard matrix for projection onto xz-plane
            ans[0] = matrix[0]; // x remains the same
            ans[1] = 0;         // y is set to 0
            ans[2] = matrix[2]; // z remains the same
            break;

        case 3: // Projection onto yz-plane
            // Standard matrix for projection onto yz-plane
            ans[0] = 0;         // x is set to 0
            ans[1] = matrix[1]; // y remains the same
            ans[2] = matrix[2]; // z remains the same
            break;

        case 4: // Reflection about the xy-plane
            // Standard matrix for reflection about the xy-plane
            ans[0] = matrix[0]; // x remains the same
            ans[1] = matrix[1]; // y remains the same
            ans[2] = -matrix[2]; // z is negated
            break;

        case 5: // Reflection about the xz-plane
            // Standard matrix for reflection about the xz-plane
            ans[0] = matrix[0]; // x remains the same
            ans[1] = -matrix[1]; // y is negated
            ans[2] = matrix[2]; // z remains the same
            break;

        case 6: // Reflection about the yz-plane
            // Standard matrix for reflection about the yz-plane
            ans[0] = -matrix[0]; // x is negated
            ans[1] = matrix[1]; // y remains the same
            ans[2] = matrix[2]; // z remains the same
            break;

        default:
            cout << "Invalid choice! Please select a valid transformation." << endl;
            continue; // Restart the loop for valid input
        }

        cout << "Transformed vector: (" << ans[0] << ", " << ans[1] << ", " << ans[2] << ")" << endl;

        char choice;
        cout << "Do you want to further transform the current vector (y/n)? ";
        cin >> choice;
        if (choice == 'n')
        {
            cout << "Do you want to input a new vector (y/n)? ";
            cin >> choice;
            if (choice == 'y')
            {
                input3D(matrix); // Input new 3D vector
            }
            else
            {
                cout << "Exiting to main menu." << endl;
                break; // Exit to main menu
            }
        }
    }
}

// Main function
int main()
{
    while (true)
    {
        int choice;
        cout << "Select the dimension for transformation: " << endl;
        cout << "1. 2D" << endl
             << "2. 3D" << endl
             << "3. Exit" << endl; // Added exit option
        cout << "Enter your choice: ";
        cin >> choice;
        

        if (choice == 1)
        {
            solve_2D(); // Call 2D transformation function
        }
        else if (choice == 2)
        {
            solve_3D(); // Call 3D transformation function
        }
        else if (choice == 3)
        {
            cout << "Exiting the program." << endl;
            break; // Exit the program
        }
        else
        {
            cout << "Invalid choice! Please select a valid option." << endl;
        }
    }

    return 0;
}