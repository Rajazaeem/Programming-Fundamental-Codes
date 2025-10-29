#include <iostream>
using namespace std;
int swap(int a, int b);
int main()
{
     int number1, number2;
     cout << "Enter the first number: ";
     cin >> number1;
     cout << "Enter the second number: ";
     cin >> number2;
     swap(number1, number2);
     return 0;
}

int swap(int a, int b)
{
     int temp = a;
     a = b;
     b = temp;
     cout << "Two numbers have been swaped " << endl
          << "RThe first number is now: " << a << "\nThe second number is now: " << b << endl;
}