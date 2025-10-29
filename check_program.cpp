#include <iostream>
#include <string>
using namespace std;

class Binary
{
    string s;

public:
    void read();
    void chk_binary();
    void comp();
    void display();
};
void Binary ::read()
{
    cout << "Enter Binary Number: ";
    cin >> s;
}
void Binary ::chk_binary()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '1' && s.at(i) != '0')
        {
            cout << "Invalid Binary Number";
            exit(1);
        }
    }
}
void Binary ::comp()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '1')
        {
            s.at(i) = '0';
        }
        else
        {
            s.at(i) = '1';
        }
    }
}
void Binary ::display()
{
    cout << "Displaying complimented Binary Number" << endl;
    cout << s;
}
int main()
{
    Binary b;
    b.read();
    b.chk_binary();
    b.comp();
    b.display();
    return 0;
}