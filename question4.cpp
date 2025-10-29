#include <iostream>
#include <string>

using namespace std;

class entry
{
public:
    string name;
    long long id_card_no;
    string address;

    void input()
    {
        cout << "Enter your details" << endl;
        cout << "\nName: ";
        getline(cin, name);
        do
        {
            cout << "\n (13 digits)ID Card No: ";
            cin >> id_card_no;
            if (id_card_no < 1000000000000 || id_card_no > 9999999999999)
            {
                cout << "Error: ID Card No must be exactly 13 digits long. Try again!\n";
            }

        } while (id_card_no < 1000000000000 || id_card_no > 9999999999999);
        cout << "\nAddress: ";
        cin.ignore();
        getline(cin, address);
    }
};

void display(entry f);

int main()
{
    entry e;
    e.input();
    display(e);
}
void display(entry f)
{
    cout << "\nName: " << f.name << endl;
    cout << "\nID Card No: " << f.id_card_no << endl;
    cout << "\nAddress: " << f.address << endl;
}