#include <iostream>
using namespace std;
int swap(int &a, int &b);
int main()
{
    int x, y;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;
    cout << "Before swaping" << endl
         << "the value of x is: " << x << " and the value of y is: " << y << endl;
    swap(x, y);
    cout << "After swaping" << endl
         << "the value of x is: " << x << " and the value of y is: " << y << endl;
    return 0;
}

int swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "In function" << endl
         << "the value of a is: " << a << " and the value of b is: " << b << endl;
}