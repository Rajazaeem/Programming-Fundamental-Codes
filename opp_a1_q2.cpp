#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class MovieTicket
{
private:
    int ticket_ID;
    string movie_Name, show_Time, seat_Type, format_Type, booking_Time;
    double base_Price = 10, final_Price = 0;

public:
    MovieTicket()
    { // Default constructor
        ticket_ID = 0;
        movie_Name = "Harry Potter";
        show_Time = "01:00";
        seat_Type = "Standard";
        format_Type = "2D";
        booking_Time = "12:45";
        final_Price = 10;
    }
    // Parameterized constructor
    MovieTicket(int tic_ID, string Mov_name, string show_time, string seat_type, string form_Type, string book_Time)
    {
        ticket_ID = tic_ID;
        movie_Name = Mov_name;
        show_Time = show_time;
        seat_Type = seat_type;
        format_Type = form_Type;
        booking_Time = book_Time;
    }

    void calculateFinalPrice()
    {
        final_Price = base_Price;

        // Check seat type with all possible case variations
        if (seat_Type == "Premium" || seat_Type == "premium" || seat_Type == "PREMIUM")
        {
            final_Price += 5;
        }
        else if (seat_Type == "VIP" || seat_Type == "vip" || seat_Type == "Vip")
        {
            final_Price += 10;
        }
        else
        {
            cout << "Please enter a valid seat type" << endl;
        }
        // Check format type with all possible case variations
        if (format_Type == "3D" || format_Type == "3d" || format_Type == "3d")
        {
            final_Price += 3;
        }
        else if (format_Type == "IMAX" || format_Type == "imax" || format_Type == "Imax")
        {
            final_Price += 7;
        }
        else
        {
            cout << "Please enter a valid format type" << endl;
        }
    }

    void getTicketDetails()
    {
        cout << "Ticket ID: " << ticket_ID << endl;
        cout << "Movie Name: " << movie_Name << endl;
        cout << "Show Time: " << show_Time << endl;
        cout << "Booking Time: " << booking_Time << endl;
        cout << "Seat Type: " << seat_Type << endl;
        cout << "Format Type: " << format_Type << endl;
        cout << fixed << setprecision(2); // Ensures price is displayed properly
        cout << "Base Price: $" << base_Price << endl;
        cout << "Final Price: $" << final_Price << endl;
    }
};

int main()
{
    int ticketID;
    string moviename, movietime, bookingTime, seattype, formattype;
    char choice;
    cout << "\n                                   ------Movie Ticket Booking System------\n";
    do
    {
        cout << "\nTicket ID: ";
        cin >> ticketID;
        cin.ignore(); // Avoid issues when taking string input after an integer

        cout << "Movie Name: ";
        getline(cin, moviename);

        cout << "Movie Time: ";
        getline(cin, movietime);

        cout << "Booking Time: ";
        getline(cin, bookingTime);

        cout << "Seat Type: ";
        getline(cin, seattype);

        cout << "Format Type: ";
        getline(cin, formattype);

        MovieTicket mt(ticketID, moviename, movietime, seattype, formattype, bookingTime);
        mt.calculateFinalPrice();
        cout << "\n                                    ------Ticket Details------\n";
        mt.getTicketDetails(); // Display ticket details
        cout << "\nWould you like to make another booking?(y/n):";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    cout << "\n                              ------Thank You For Using Movie Ticket Booking System-------\n";

    return 0;
}