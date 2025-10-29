#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 0;
    cout << "Enter the key: ";
    cin >> key;
    int n=10;
    int index=-1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            index = i;
            arr[i] = index-i;
            n--;
        }
        if (index !=-1)
        {
            arr[i] = arr[i+1];
        }
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    if (index == -1)
    {
        cout << "Key not found";
    }

    return 0;
}