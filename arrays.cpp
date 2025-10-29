#include <iostream>
using namespace std;

int main() {
    // Declare and initialize an integer array of size 6 with 12
    int intArray[6] = {12, 12, 12, 12, 12, 12};

    // Declare and initialize a float array of size 5 with 0.5
    float floatArray[5] = {0.5, 0.5, 0.5, 0.5, 0.5};

    // Declare and initialize a character array of size 4 with 'a'
    char charArray[4] = {'a', 'a', 'a', 'a'};

    // Display the arrays
    cout << "Integer array: ";
    for (int i = 0; i < 6; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    cout << "Float array: ";
    for (int i = 0; i < 5; i++) {
        cout << floatArray[i] << " ";
    }
    cout << endl;

    cout << "Character array: ";
    for (int i = 0; i < 4; i++) {
        cout << charArray[i] << " ";
    }
    cout << endl;

    return 0;
}