#include <iostream>
using namespace std;

// Function prototype
int sumOfNumbers(int num);

int main() {
    int num;

    cout << "Enter a positive integer: ";
    cin >> num;

    // Call the function and display the result
    cout << "The sum of numbers from 1 to " << num << " is: " << sumOfNumbers(num) << endl;

    return 0;
}

// Function definition
int sumOfNumbers(int num) {
    int sum = 0;

    for (int i = 1; i <= num; ++i) {
        sum += i; // Add the current number to the sum
    }

    return sum; // Return the total sum
}
