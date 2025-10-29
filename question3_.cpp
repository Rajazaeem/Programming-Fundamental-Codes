#include <iostream>

using namespace std;

class measure
{
private:
    float length, width, area;

public:
    measure()
    {
        length = 0;
        width = 0;
    }
    measure(float l, float w)
    {
        length = l;
        width = w;
    }
    float calculate(float l, float w)
    {
        area = length * width;
    }
    void display()
    {
        cout << "\nArea of rectangle is " << area << endl;
    }
};

int main()
{
    measure m1, m2(5, 6);
    m2.calculate(5.34, 6.56);
    m2.display();

    cout << endl;
    return 0;
}