#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

// Base class representing generic shape properties
class shapes
{
private:
    string color; // Color of the shape

public:
    // Setter for color
    void setcolor(string c)
    {
        color = c;
    }

    // Getter for color
    string getcolor()
    {
        return color;
    }

    // Virtual area function to be overridden in derived classes
    double area()
    {
        return -1;
    }

    // Display basic shape info
    void display()
    {
        cout << "Color is " << color << endl;
    }
};

// Derived class for Triangle, inherits from shapes
class triangle : public shapes
{
private:
    const string shape = "Triangle"; // Shape name
    double base;                     // Base of triangle
    double hight;                    // Height of triangle
    double number_of_sides;          // Number of sides (always 3 for triangle)

public:
    // Function to set triangle data
    void set_triangle(double b, double h)
    {
        base = b;
        hight = h;
        number_of_sides = 3;
    }

    // Function to take input from user
    void input()
    {
        double base, hight;
        cout << "Enter base of a triangle: ";
        cin >> base;
        cout << "Enter height of a triangle: ";
        cin >> hight;
        set_triangle(base, hight);
    }

    // Function to calculate area of triangle
    double area()
    {
        cout << fixed << setprecision(2); // Format output
        return 0.5 * (base * hight);
    }

    // Function to display triangle details
    void display()
    {
        cout << "\nName of shape is: " << shape << endl;
        cout << "Color of " << shape << ": " << getcolor() << endl;
        cout << "Base: " << base << endl;
        cout << "Height: " << hight << endl;
        cout << "Number of sides: " << number_of_sides << endl;
        cout << "Area: " << triangle::area() << endl;
    }
};

// Derived class for Circle, inherits from shapes
class circle : public shapes
{
private:
    const string shape = "Circle"; // Shape name
    double radius;                 // Radius of circle
    double center1;                // X coordinate of center
    double center2;                // Y coordinate of center

public:
    // Function to set circle data
    void set_circle(double r, double c1, double c2)
    {
        radius = r;
        center1 = c1;
        center2 = c2;
    }

    // Function to take input from user
    void input()
    {
        double radius, center1, center2;
        cout << "\nEnter radius of a circle: ";
        cin >> radius;
        cout << "Enter center1 of a circle: ";
        cin >> center1;
        cout << "Enter center2 of a circle: ";
        cin >> center2;
        set_circle(radius, center1, center2);
    }

    // Function to calculate circumference of circle
    float circumference()
    {
        cout << fixed << setprecision(2);
        return 2 * 3.14 * radius;
    }

    // Function to calculate diameter of circle
    float diameter()
    {
        return 2 * radius;
    }

    // Function to display circle details
    void display()
    {
        cout << "\nName of shape is: " << shape << endl;
        cout << "Color of " << shape << ": " << getcolor() << endl;
        cout << "Radius: " << radius << endl;
        cout << "Center1: " << center1 << endl;
        cout << "Center2: " << center2 << endl;
        cout << "Circumference: " << circumference() << endl;
        cout << "Diameter: " << diameter() << endl;
    }
};

// Main function
int main()
{
    // Creating triangle object and setting its properties
    triangle t1;
    t1.setcolor("blue");
    t1.input(); // Take input from user

    // Display triangle information
    cout << "\n ---------- The information of a triangle ---------- \n";
    t1.display();

    // Creating circle object and setting its properties
    circle c1;
    c1.input(); // Take input from user
    c1.setcolor("yellow");

    // Display circle information
    cout << "\n ---------- The information of a circle ---------- \n";
    c1.display();

    return 0;
}