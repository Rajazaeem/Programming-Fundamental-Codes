#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  string n;
  ofstream i;
  i.open("Task.txt");
  cout << "Enter the heading: ";
  getline(cin, n);
  i << "heading you entered: " << n << endl;
  i << "My name is Zaeem" << endl
    << "student of Air university Kharian" << endl
    << "And i am in university now" << endl;
  i.close();
  string s;
  cout << "Please enter a line:" << endl;
  getline(cin, s);
  cout << s;
  i.open("Task.txt");

  string read;
  while ((getline, read))
    cout << read << endl;
  return 0;
}