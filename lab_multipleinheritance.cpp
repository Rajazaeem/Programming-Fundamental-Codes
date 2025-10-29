#include <iostream>
#include <string>

using namespace std;

class student
{
private:
    int id;
    string name;

public:
    void setdata(int id, string name);
    void show()
    {
        cout << "The name of the student is: " << name << endl
             << "Id of the student is: " << id;
    }
};
void student ::setdata(int id, string name)
{
    this->id = id;
    this->name = name;
}

class result
{
private:
    float opp, dld, linear;

public:
    void input(float opp, float dld, float linear);
    void getresult()
    {
        cout << "The number of opp is: " << opp << endl
             << "The number of dld is: " << dld << endl
             << "The number of linear is: " << linear << endl;
        float sum = opp + dld + linear;
        cout << "The sum of opp,dld,linear is: " << sum;
    }
};

void result ::input(float opp, float dld, float linear)
{
    this->opp = opp;
    this->dld = dld;
    this->linear = linear;
}

class displaydata : public student, public result
{
public:
    void display()
    {
        student :: show();
        result :: getresult();
       
    }
};

int main()
{
    displaydata obj;
    obj.setdata(1, "Zaeem Furqan");
    obj.input(90, 80, 70);
    obj.display();

    return 0;
}