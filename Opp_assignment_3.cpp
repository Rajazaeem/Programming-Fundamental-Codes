#include <iostream>
#include <string>

using namespace std;

// Base class for common attributes of publications
class publication
{
private:
    string title; // Title of the publication
    float price;  // Price of the publication

public:
    // Function to set the title and price of the publication
    void setdata(string t, float p)
    {
        title = t;
        price = p;
    }

    // Function to display the title and price of the publication
    void putdata()
    {
        cout << "Title of a book: " << title << endl;
        cout << "Price of a book: " << price << endl;
    }

    // Getter for price
    float get_price()
    {
        return price;
    }

    // Getter for title
    string get_title()
    {
        return title;
    }
};

// Derived class for Book, inherits from publication
class book : public publication
{
private:
    int page_count; // Number of pages in the book

public:
    // Function to set all book data including inherited and specific
    void setdata(int page_count, string title, float price)
    {
        publication::setdata(title, price); // Set title and price using base class method
        this->page_count = page_count;
    }

    // Function to get book data from the user
    void getdata()
    {
        string title;
        float price;
        int page_count;

        cout << "Enter the title of the book: ";
        getline(cin, title); // Input book title

        cout << "Enter the price of the book: ";
        cin >> price; // Input book price

        cout << "Enter the page count of the book: ";
        cin >> page_count; // Input number of pages

        setdata(page_count, title, price); // Set data
    }

    // Function to display book details
    void putdata()
    {
        cout << endl << "\n---------- Book Details -----------------" << endl;
        publication::putdata(); // Display title and price
        cout << "Page count: " << page_count << endl; // Display page count
    }
};

// Derived class for Tape, inherits from publication
class tape : public publication
{
private:
    float playing_time; // Playing time of the tape in minutes

public:
    // Function to set all tape data including inherited and specific
    void setdata(float playing_time, string title, float price)
    {
        publication::setdata(title, price); // Set title and price using base class method
        this->playing_time = playing_time;
    }

    // Function to get tape data from the user
    void getdata()
    {
        string title;
        float price, playing_time;

        cin.ignore(); // Clear input buffer to avoid skipping getline
        cout << endl << "Enter the title of the tape: ";
        getline(cin, title); // Input tape title

        cout << "Enter the price of the tape: ";
        cin >> price; // Input tape price

        cout << "Enter the playing time of the tape in (minutes): ";
        cin >> playing_time; // Input playing time

        setdata(playing_time, title, price); // Set data
    }

    // Function to display tape details
    void putdata()
    {
        cout << endl << "\n---------- Tape Details -----------------" << endl;
        cout << "Title of a tape: " << get_title() << endl; // Display title using getter
        cout << "Price of a tape: " << get_price() << endl; // Display price using getter
        cout << "Playing time of a tape: " << playing_time << " minutes" << endl;
    }
};

// Main function
int main()
{
    // Create a book object and get its details
    book b1;
    b1.getdata(); // Get data from user
    b1.putdata(); // Display book info

    // Create a tape object and get its details
    tape t1;
    t1.getdata(); // Get data from user
    t1.putdata(); // Display tape info

    return 0;
}