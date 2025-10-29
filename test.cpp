#include <iostream>
#include <string>
using namespace std;

template <typename T>
T function(T x, T y) {
    return x+y;
}
string function(char x, char y) {
    return string(1, x) + string(1, y);
}


// Overload for char to return concatenated string

int main() {
    cout << "Int  add: " << function<int>(2, 3) << endl; 
    cout << "Float add: " << function<float>(1.1f, 2.2f) << endl;
    cout << "Char  add: " << function<char>('a', 'z') << endl;
    cout << "String add: " << function<string>("Hello ", "World!") << endl;
   
    return 0;
}