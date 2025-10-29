#include <iostream>
using namespace std;

class Book
{
private:
    int No;
    string Name;

public:
    void add_book(int n, string book)
    {
        No = n;
        Name = book;
    }
    void display_book()
    {
        cout << "Book No: " << No << endl;
        cout << "Book Name: " << Name << endl;
    }
};

int main()
{

    string book = "python";
    Book b;
    b.add_book(1, book);
    b.display_book();
    return 0;
}