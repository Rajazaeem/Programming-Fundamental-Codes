#include <iostream>
#include <string>

using namespace std;

class students
{
public:
    string name;
    int age;
    // Ddefault constructure..
    students()
    {
        name = "ali";
        age = 12;
    }

    // Paramiterize constructure..
    students(string a, int n)
    {
        name = a;
        age = n;
    }
};
// Main function...
int main()
{
    students s1;
    cout << s1.name << endl;
    cout << s1.age << endl;
    // Paramiterize constructure..
    students s2("Zaeem", 20);
    cout << "Peramiterize constructure values:" << endl;
    cout << s2.name << endl;
    cout << s2.age << endl;

    return 0;
}