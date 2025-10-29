#include <iostream>
#include <cmath>
#include <limits> // Include for numeric_limits

#ifndef M_PI
#define M_PI 3.14159265358979323846 // For defining the PI 
#endif
using namespace std;

// Function to input and validate a 2D vector
void input2D(double matrix[2])
{
    while (true)
    {
        cout << "Enter the 2D vector (2x1 matrix): ";
        if (cin >> matrix[0] >> matrix[1])
        {
            break; // Input is valid
        }
        else
        {
            cout << "Invalid input! Please enter two numbers for the 2D vector: ";
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    }
}

// Function to input and validate a 3D vector
void input3D(double matrix[3])
{
    while (true)
    {
        cout << "Enter the 3D vector (3x1 matrix): ";
        if (cin >> matrix[0] >> matrix[1] >> matrix[2])
        {
            break; // Input is valid
        }
        else
        {
            cout << "Invalid input! Please enter three numbers for the 3D vector: ";
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
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
            ans[0] = matrix[0];
            ans[1] = 0;
            break;

        case 2: // Projection onto y-axis
            ans[0] = 0;
            ans[1] = matrix[1];
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
                ans[0] = matrix[0];       // horizontal unchanged
                ans[1] = k * matrix[1];   // vertical expanded
            }
            else // horizontal
            {
                ans[0] = k * matrix[0];   // horizontal expanded
                ans[1] = matrix[1];       // vertical unchanged
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
                ans[0] = matrix[0];       // horizontal unchanged
                ans[1] = k * matrix[1];   // vertical dilated
            }
            else // horizontal
            {
                ans[0] = k * matrix[0];   // horizontal dilated
                ans[1] = matrix[1];       // vertical unchanged
            }
            break;
        }

        case 5: // Shear
        {
            char dim;
            do
            {
                cout << "Perform horizontal (h) or vertical (v) shear? (h/v): ";
                cin >> dim;
                if (dim != 'h' && dim != 'v')
                {
                    cout << "Invalid choice! Please enter 'h' for horizontal or 'v' for vertical." << endl;
                }
            } while (dim != 'h' && dim != 'v');

            double k;
            cout << "Enter shear factor: ";
            cin >> k;

            if (dim == 'h')
            {
                ans[0] = matrix[0] + k * matrix[1];
                ans[1] = matrix[1];
            }
            else // vertical shear
            {
                ans[0] = matrix[0];
                ans[1] = matrix[1] + k * matrix[0];
            }
            break;
        }

        case 6: // Rotation
        {
            double angle;
            cout << "Enter rotation angle in degrees: ";
            cin >> angle;
            double radians = angle * (M_PI / 180.0);
            ans[0] = matrix[0] * cos(radians) - matrix[1] * sin(radians);
            ans[1] = matrix[0] * sin(radians) + matrix[1] * cos(radians);
            break;
        }

        default: // Invalid choice
            cout << "Invalid choice!" << endl;
            return;
        }

        // Displaying the result of the transformation
        cout << "Result of transformation:\n[ " << ans[0] << " ]\n[ " << ans[1] << " ]\n";

        char exitChoice;
        cout << "Do you want to exit? (y/n): ";
        cin >> exitChoice;
        if (exitChoice == 'y' || exitChoice == 'Y')
        {
            break; // Exit the transformation loop
        }

        char continueChoice;
        cout << "Do you want to perform another transformation on the existing vector (e) or enter a new vector (n)? (e/n): ";
        cin >> continueChoice;
        if (continueChoice == 'n')
        {
            input2D(matrix); // Input a new 2D vector
        }
        else if (continueChoice != 'e')
        {
            cout << "Invalid choice! Exiting the transformation loop." << endl;
            break; // Exit the loop to return to the main menu
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
             << "4. Expansion" << endl
             << "5. Dilation" << endl
             << "6. Shear" << endl
             << "7. Rotation about x-axis" << endl
             << "8. Rotation about y-axis" << endl
             << "9. Rotation about z-axis" << endl;

        cout << "Enter your choice: ";
        cin >> c;

        switch (c)
        {
        case 1: // Projection onto xy-plane
            ans[0] = matrix[0];
            ans[1] = matrix[1];
            ans[2] = 0;
            break;

        case 2: // Projection onto xz-plane
            ans[0] = matrix[0];
            ans[1] = 0;
            ans[2] = matrix[2];
            break;

        case 3: // Projection onto yz-plane
            ans[0] = 0;
            ans[1] = matrix[1];
            ans[2] = matrix[2];
            break;

        case 4: // Expansion
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
                // vertical expansion: scale y and z components
                ans[0] = matrix[0];
                ans[1] = k * matrix[1];
                ans[2] = k * matrix[2];
            }
            else // horizontal expansion: scale x component only
            {
                ans[0] = k * matrix[0];
                ans[1] = matrix[1];
                ans[2] = matrix[2];
            }
            break;
        }

        case 5: // Dilation
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
                ans[0] = matrix[0];
                ans[1] = k * matrix[1];
                ans[2] = k * matrix[2];
            }
            else // horizontal
            {
                ans[0] = k * matrix[0];
                ans[1] = matrix[1];
                ans[2] = matrix[2];
            }
            break;
        }

        case 6: // Shear
        {
            char dim;
            do
            {
                cout << "Perform horizontal (h) or vertical (v) shear? (h/v): ";
                cin >> dim;
                if (dim != 'h' && dim != 'v')
                {
                    cout << "Invalid choice! Please enter 'h' for horizontal or 'v' for vertical." << endl;
                }
            } while (dim != 'h' && dim != 'v');

            double k;
            cout << "Enter shear factor: ";
            cin >> k;

            if (dim == 'h')
            {
                ans[0] = matrix[0] + k * matrix[1];
                ans[1] = matrix[1];
                ans[2] = matrix[2];
            }
            else // vertical shear
            {
                ans[0] = matrix[0];
                ans[1] = matrix[1] + k * matrix[0];
                ans[2] = matrix[2];
            }
            break;
        }

        case 7: // Rotation about x-axis
        {
            double angle;
            cout << "Enter rotation angle in degrees: ";
            cin >> angle;
            double radians = angle * (M_PI / 180.0);
            ans[0] = matrix[0];
            ans[1] = matrix[1] * cos(radians) - matrix[2] * sin(radians);
            ans[2] = matrix[1] * sin(radians) + matrix[2] * cos(radians);
            break;
        }

        case 8: // Rotation about y-axis
        {
            double angle;
            cout << "Enter rotation angle in degrees: ";
            cin >> angle;
            double radians = angle * (M_PI / 180.0);
            ans[0] = matrix[0] * cos(radians) + matrix[2] * sin(radians);
            ans[1] = matrix[1];
            ans[2] = -matrix[0] * sin(radians) + matrix[2] * cos(radians);
            break;
        }

        case 9: // Rotation about z-axis
        {
            double angle;
            cout << "Enter rotation angle in degrees: ";
            cin >> angle;
            double radians = angle * (M_PI / 180.0);
            ans[0] = matrix[0] * cos(radians) - matrix[1] * sin(radians);
            ans[1] = matrix[0] * sin(radians) + matrix[1] * cos(radians);
            ans[2] = matrix[2];
            break;
        }

        default: // Invalid choice
            cout << "Invalid choice!" << endl;
            return;
        }

        // Displaying the result of the transformation
        cout << "Result of transformation:\n[ " << ans[0] << " ]\n[ " << ans[1] << " ]\n[ " << ans[2] << " ]\n";

        char exitChoice;
        cout << "Do you want to exit? (y/n): ";
        cin >> exitChoice;
        if (exitChoice == 'y' || exitChoice == 'Y')
        {
            break; // Exit the transformation loop
        }

        char continueChoice;
        cout << "Do you want to perform another transformation on the existing vector (e) or enter a new vector (n)? (e/n): ";
        cin >> continueChoice;
        if (continueChoice == 'n')
        {
            input3D(matrix); // Input a new 3D vector
        }
        else if (continueChoice != 'e')
        {
            cout << "Invalid choice! Exiting the transformation loop." << endl;
            break; // Exit the loop to return to the main menu
        }
    }
}

int main()
{
    int choice;

    while (true)
    {
        cout << "Select type of linear transformation:\n1. 2D\n2. 3D\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            solve_2D();
            // After solve_2D returns, main menu prompt will appear again
        }
        else if (choice == 2)
        {
            solve_3D();
            // After solve_3D returns, main menu prompt will appear again
        }
        else if (choice == 3)
        {
            cout << "Exiting the program!" << endl;
            break;
        }
        else
        {
            cout << "Please enter a valid choice!" << endl;
        }
    }

    return 0;
}