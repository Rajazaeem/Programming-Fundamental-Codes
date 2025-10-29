#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double convertKPHtoMPH(int kph);

int main()
{
    cout << left << setw(10) << "KPH" << "MPH" << endl;
    cout << "----------------" << endl;

    // Loop through the given range and display the conversions
    for (int kph = 60; kph <= 130; kph += 10)
    {
        double mph = convertKPHtoMPH(kph); // Call the conversion function
        cout << left << setw(10) << kph << fixed << setprecision(1) << mph << endl;
    }

    return 0;
}

// Function definition
double convertKPHtoMPH(int kph)
{
    return kph * 0.6214; // Conversion formula
}
