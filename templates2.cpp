#include <iostream>
#include <string>
using namespace std;

template <typename T>
T function(T x, T y) {
    return x + y;
}

// Overload for char to return concatenated string
string function(char x, char y) {
    return string(1, x) + string(1, y);
}

int main() {
    cout << "Char add: " << function('a', 'z') << endl; // az
    cout << "Float add: " << function(1.1f, 2.2f) << endl;
    cout << "Int add: " << function(3, 7) << endl;
    cout << "String add: " << function(string("Hello "), string("World!")) << endl;
    return 0;
}