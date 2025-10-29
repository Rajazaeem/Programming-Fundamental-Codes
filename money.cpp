#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
float normalizeMoney(float rupees, int paisas = 150);

int main() {
    int paisas;
    float rupees = 0;

    cout << setprecision(2) << fixed << showpoint;

    paisas = 95;
    cout << "\nWe will now add 95 paisas to our rupees total\n";
    rupees = normalizeMoney(rupees, paisas); // Call the function with 95 paisas
    cout << "Converting paisas to rupees resulted in " << rupees << " rupees\n";

    cout << "\nWe will now add 193 paisas to our rupees total\n";
    paisas = 193;
    rupees = normalizeMoney(rupees, paisas); // Call the function with 193 paisas
    cout << "Converting paisas to rupees resulted in " << rupees << " rupees\n";

    cout << "\nWe will now add the default value to our rupees total\n";
    rupees = normalizeMoney(rupees); // Call the function with the default value
    cout << "Converting paisas to rupees resulted in " << rupees << " rupees\n";

    return 0; 
}

// Function definition
float normalizeMoney(float currRupees, int paisas) {
    float paisa2Rup = paisas / 100.0; // Convert paisas to rupees
    return currRupees + paisa2Rup;   // Add converted paisas to the current rupees and return
}
