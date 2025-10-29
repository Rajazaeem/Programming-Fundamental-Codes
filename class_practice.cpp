#include <iostream>
using namespace std;
int main()
{
    int array[2][3] = {{0, 1, 2}, {3, 4, 5}};
    int(*ptr)[3] = array;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << (*ptr)[0];
    cout << (*ptr)[4];
    cout << array << endl
         << &array[0] << endl;
    cout << *array << endl
         << array[0] << endl
         << &array[0][0] << endl;
    cout << array + 1 << endl;

    return 0;
}