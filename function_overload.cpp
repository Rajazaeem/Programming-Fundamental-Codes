#include <iostream>
#include <string>
using namespace std;
int add(int a, int b);
void show_string(string a);
float add(float a, float b);
int main()
{
    float x, y;
    string str;
    char choice;
    cout << "Choose the given option\n"
         << "1: for sume of float or integer numbers\n"
         << "2: for display the string" << endl;
    cin >> choice;
    switch (choice)
    {
    case '1':
        cout << "Enter the value of x: ";
        cin >> x;
        cout << "Enter the value of y: ";
        cin >> y;

        cout << endl;

        add(x, y);
        break;
    case '2':
        cout << "Enter the string: ";
        cin >> str;
        show_string(str);
        break;
    default:
        cout << "Enter the correct coice!" << endl;
    }
    return 0;
}
int add(int a, int b)
{
    int sum = a + b;
    cout << "Sum of given number is: " << sum << endl;
    return sum;
}
void show_string(string a)
{

    cout <<"The string you entered is: "<< a<<endl;
}
float add(float a, float b)
{
    float sum = a + b;
    cout << "Sum of given number is: " << sum << endl;
    return sum;
}