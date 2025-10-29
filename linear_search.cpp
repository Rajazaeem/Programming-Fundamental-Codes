#include <iostream>
using namespace std;

// function to perform linear search.
int linearsearch(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
    { // loop through each element
        if (arr[i] == x)
        {             // if element matches x
            return i; // return the index.
        }
    }
    return -1; // return -1 if x is not found
}
int main()
{
    int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20}; // the array of nmbers
    int size = sizeof(arr) / sizeof(arr[0]);          // calculated the size of array
    int x = 55;                                       // the number to search for

    // call linearsearch function
    int result = linearsearch(arr, size, x);

    // output the result
    if (result != -1)
    { // if result not -1, x was not found
        cout << "Element " << x << " found at index " << result << "." << endl;
    }
    else
    { // if result is -1, x was not found
        cout << "Element " << x << " not found in the array." << endl;
    }
    return 0;
}