#include <iostream>
#include <stdexcept>
#include <fstream>
#include <ctime>

using namespace std;

class SecureMatrix {
private:
    int data[2][2]; // 2x2 matrix to store integer values
    string logFile; // Log file name for storing operations

    // Function to log operations performed on the matrix
    void logOperation(const string &operation) const {
        ofstream logfile(logFile, ios::app); // Open log file in append mode
        if (logfile.is_open()) {
            time_t now = time(0); // Get the current time
            char *dt = ctime(&now); // Convert time to string format
            logfile << operation << " at " << dt; // Log the operation with timestamp
            logfile.close(); // Close the log file to save changes
        }
    }

public:
    // Constructor to initialize the matrix with input validation
    SecureMatrix(int a, int b, int c, int d) : logFile("audit.txt") {
        // Check if values exceed the maximum limit
        if (a > 1000 || b > 1000 || c > 1000 || d > 1000) {
            throw runtime_error("Error: Value exceeds maximum limit.");
        }
        data[0][0] = a; // Set value to matrix
        data[0][1] = b; // Set value to matrix
        data[1][0] = c; // Set value to matrix
        data[1][1] = d; // Set value to matrix
    }

    // Overloaded + operator for matrix addition
    SecureMatrix operator+(const SecureMatrix &other) const {
        SecureMatrix result(0, 0, 0, 0); // Create a result matrix initialized to zeros
        for (int i = 0; i < 2; ++i) { // Iterate over the rows
            for (int j = 0; j < 2; ++j) { // Iterate over the columns
                long long sum = static_cast<long long>(data[i][j]) + static_cast<long long>(other.data[i][j]); // Prevent overflow
                // Check for overflow
                if (sum > 1000) {
                    throw overflow_error("Error: Integer overflow in addition.");
                }
                result.data[i][j] = static_cast<int>(sum); // Store the sum in the result matrix
            }
        }
        logOperation("Added matrices"); // Log the addition operation
        return result; // Return the result matrix
    }

    // Friend function to audit the matrix state
    friend void auditMatrix(const SecureMatrix &m); // Declaration of friend function

    // Function to display the matrix
    void display() const {
        cout << "[ " << data[0][0] << ", " << data[0][1] << " ; "
             << data[1][0] << ", " << data[1][1] << " ]" << endl; // Print the matrix
    }
};

// Implementation of the audit function
void auditMatrix(const SecureMatrix &m) {
    ofstream logfile(m.logFile, ios::app);
    if (logfile.is_open()) {
        logfile << "Current matrix state: [ " 
                 << m.data[0][0] << ", " << m.data[0][1] << " ; "
                 << m.data[1][0] << ", " << m.data[1][1] << " ]" << endl;
        logfile.close();
    }
}

// Function to get user input and create a SecureMatrix
SecureMatrix getMatrixFromUser(const string &matrixName) {
    int a, b, c, d;

    cout << "Enter values for " << matrixName << " (four integers separated by spaces): ";
    cin >> a >> b >> c >> d;

    return SecureMatrix(a, b, c, d); // Call constructor
}

// Main program: entry point
int main() {
    try {
        // Get matrix A values from user
        SecureMatrix A = getMatrixFromUser("Matrix A");
        cout << "Matrix A = ";
        A.display(); // Display matrix A

        // Get matrix B values from user
        SecureMatrix B = getMatrixFromUser("Matrix B");
        cout << "Matrix B = ";
        B.display(); // Display matrix B

        // Add matrices A and B
        SecureMatrix C = A + B;
        cout << "Matrix A + B = ";
        C.display(); // Display the result of A + B

    } catch (const exception &e) {
        cout << e.what() << endl; // Catch and display any exceptions that occur during matrix creation or addition
    }

    // Example of invalid input to demonstrate error handling
    try {
        SecureMatrix D(1001, 0, 0, 0); // Attempt to create an invalid matrix
    } catch (const exception &e) {
        cout << e.what() << endl; // Display error for invalid input
    }

    return 0; // End of the program
}