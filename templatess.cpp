#include <iostream>
#include <string>
#include <type_traits> // for std::enable_if

using namespace std;

template <typename T>
class Templates {
    T num, num1;

public:
    Templates(T a = 0, T b = 0) : num(a), num1(b) {}

    // Generic add for all types EXCEPT const char* and char
    template <typename U = T>
    typename std::enable_if<!std::is_same<U, const char*>::value && !std::is_same<U, char>::value, U>::type
    add(U a, U b) {
        return a + b;
    }

    // Overload for const char* — only enabled when T is const char*
    template <typename U = T>
    typename std::enable_if<std::is_same<U, const char*>::value, string>::type
    add(const char* a, const char* b) {
        return string(a) + string(b);
    }

    // Overload for char — only enabled when T is char
    template <typename U = T>
    typename std::enable_if<std::is_same<U, char>::value, string>::type
    add(char a, char b) {
        return string(1, a) + string(1, b);
    }
    

    Templates operator+(const Templates& other) {
        return Templates(num + other.num, num1 + other.num1);
    }

    void display() const {
        cout << "(" << num << ", " << num1 << ")";
    }
};

int main() {
    Templates<int> tInt(3, 5);
    Templates<int> tInt2(2, 6);
    Templates<float> tFloat;
    Templates<char> tChar;
    Templates<const char*> tStr;

    // Valid uses of add inside the class
    cout << "Char add: " << tChar.add('a', 'z') << endl;
    cout << "Float add: " << tFloat.add(1.1f, 2.2f) << endl;
    cout << "Int add: " << tInt.add(3, 7) << endl;
    cout << "String add: " << tStr.add("Hello ", "World!") << endl;

    // Operator overloading
    Templates<int> tSum = tInt + tInt2;
    cout << "Sum (operator+): ";
    tSum.display();
    cout << endl;

    return 0;
}
