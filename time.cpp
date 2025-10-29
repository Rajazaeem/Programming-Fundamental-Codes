#include <iostream>
using namespace std;

int main() {
    int minutes, seconds;
    cout << "Enter the minutes: ";
    cin >> minutes;
    cout << "Enter the seconds: ";
    cin >> seconds;

    for (int m = minutes; m >= 0; m--) {        // Outer loop for minutes
        for (int s = (m == minutes ? seconds : 59); s >= 0; s--) { // Inner loop for seconds
            cout << "\rTime left: " << m << " min " << s << " sec" << flush;
        
            // Simulate a 1-second delay
            for (volatile int i = 0; i < 100000000; ++i);
        }
    }

    cout << "\nTime is up! bye bye" << endl;
    return 0;
}