#include <iostream>
#include <cmath>

using namespace std;


 // prototype for a user defined function that
float getSqrt(int);
// returns the square root of the number passed to it
int main()
{

	cout << "Calling findSqrRoot function with a 4" << endl;
	//the calling statement and then store the return value in a variable
	float result = getSqrt(4);
    cout<<"The square root of 4 is: "<<result<<endl;
	return 0;
}
//complete the function header
float getSqrt(int x)
{
	return sqrt(x);
}