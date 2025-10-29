#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Forward declarations of derived classes
class Conference;
class Workshop;
class Concert;

// Base class for all events
class Event; // Forward declaration

// Global container for events
vector<unique_ptr<Event>> events;

// Venue class
class Venue {
private:
    const int id;
    static int total_venues;
    string name;
    int capacity;
public:
    Venue(string n, int c) : id(total_venues++), name(n), capacity(c) {}
    string getName() const { return name; }
    int getCapacity() const { return capacity; }
    static unique_ptr<Venue> create_venue() {
        string n;
        int c;
        cout << "Enter venue name: ";
        cin.ignore();
        getline(cin, n);
        cout << "Enter venue capacity: ";
        cin >> c;
        cin.ignore();
        return make_unique<Venue>(n, c);
    }
    template <typename T>
    bool canHost(T expected) const {
        return expected <= capacity;
    }
    void displaydetails() const {
        cout << "Venue name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
    }
    friend bool check_capacity(const Venue& v, int expected);
};
int Venue::total_venues = 0;

bool check_capacity(const Venue& v, int expected) {
    return v.getCapacity() >= expected;
}

// Organizer class
class Organizer {
private:
    const int id;
    static int total_organizers;
    string name;
public:
    Organizer(string n) : id(total_organizers++), name(n) {}
    string getName() const { return name; }
    static unique_ptr<Organizer> create_organizer() {
        string n;
        cout << "Enter organizer name: ";
        cin.ignore();
        getline(cin, n);
        return make_unique<Organizer>(n);
    }
    virtual void inputdetails() {
        cout << "Organizer name: " << name << endl;
    }
    virtual void displaydetails() const {
        cout << "Organizer id: " << id << "\nOrganizer name: " << name << endl;
    }
    virtual ~Organizer() = default;
};
int Organizer::total_organizers = 0;

// Attendee class
class Attendee {
private:
    const int id;
    static int total_attendees;
    string name;
public:
    Attendee(string n) : id(total_attendees++), name(n) {}
    static unique_ptr<Attendee> create_attendee() {
        string n;
        cout << "Enter attendee name: ";
        cin.ignore();
        getline(cin, n);
        return make_unique<Attendee>(n);
    }
    void displaydetails() const {
        cout << "Attendee id: " << id << endl;
        cout << "Attendee name: " << name << endl;
    }
};
int Attendee::total_attendees = 0;

// Event class (base)
class Event {
protected:
    const int id;
    static int total_events;
    string name;
    string date;
    unique_ptr<Venue> venue;
    unique_ptr<Organizer> organizer;
    vector<unique_ptr<Attendee>> attendees;

public:
    Event() : id(total_events++) {}
    virtual void inputdetails() = 0;
    virtual void displaydetails() const = 0;
    void register_attendeesForm() {
        int count;
        cout << "Enter number of attendees to register: ";
        cin >> count;
        cin.ignore();

        if (!check_capacity(*venue, count)) {
            cout << "Warning: Venue capacity exceeded!\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            attendees.push_back(Attendee::create_attendee());
        }
    }

    static void create_event() {
        int choice;
        cout << "======================Select Event Type======================\n";
        cout << "1. Conference\n"
             << "2. Workshop\n"
             << "3. Concert\n";
        cin >> choice;
        cin.ignore();
        unique_ptr<Event> event;
        switch (choice) {
            case 1:
                event = make_unique<Conference>();
                break;
            case 2:
                event = make_unique<Workshop>();
                break;
            case 3:
                event = make_unique<Concert>();
                break;
            default:
                cout << "Invalid choice\n";
                return;
        }
        event->inputdetails();
        events.push_back(move(event));
    }
    virtual ~Event() = default;
};
int Event::total_events = 0;

// Derived classes
class Conference : public Event {
public:
    void inputdetails() override {
        cout << "\n-----------Conference Details-----------\n";
        cout << "Enter conference name: ";
        getline(cin, name);
        cout << "Enter conference date: ";
        getline(cin, date);
        venue = Venue::create_venue();
        organizer = Organizer::create_organizer();
        register_attendeesForm();
    }
    void displaydetails() const override {
        cout << "\n-----------Conference Details-----------\n";
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Venue: " << venue->getName() << endl;
        cout << "Organizer: " << organizer->getName() << endl;
        cout << "Attendees:\n";
        for (const auto& attendee : attendees) {
            attendee->displaydetails();
            cout << endl;
        }
    }
};

class Workshop : public Event {
private:
    int duration;
public:
    void inputdetails() override {
        cout << "\n-----------Workshop Details-----------\n";
        cout << "Enter workshop name: ";
        getline(cin, name);
        cout << "Enter workshop date: ";
        getline(cin, date);
        cout << "Enter workshop duration (hours): ";
        cin >> duration;
        cin.ignore();
        venue = Venue::create_venue();
        organizer = Organizer::create_organizer();
        register_attendeesForm();
    }
    void displaydetails() const override {
        cout << "\n-----------Workshop Details-----------\n";
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Venue: " << venue->getName() << endl;
        cout << "Organizer: " << organizer->getName() << endl;
        cout << "Attendees:\n";
        for (const auto& attendee : attendees) {
            attendee->displaydetails();
            cout << endl;
        }
    }
};

class Concert : public Event {
private:
    string artist;
public:
    void inputdetails() override {
        cout << "\n-----------Concert Details-----------\n";
        cout << "Enter concert name: ";
        getline(cin, name);
        cout << "Enter concert date: ";
        getline(cin, date);
        cout << "Enter concert artist: ";
        getline(cin, artist);
        venue = Venue::create_venue();
        organizer = Organizer::create_organizer();
        register_attendeesForm();
    }
    void displaydetails() const override {
        cout << "\n-----------Concert Details-----------\n";
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Artist: " << artist << endl;
        cout << "Venue: " << venue->getName() << endl;
        cout << "Organizer: " << organizer->getName() << endl;
        cout << "Attendees:\n";
        for (const auto& attendee : attendees) {
            attendee->displaydetails();
            cout << endl;
        }
    }
};

int main() {
    cout << "Event Management System\n";
    cout << "How many events do you want to create? ";
    int count;
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++) {
        Event::create_event();
    }

    cout << "\n===============Event Summary===============\n";
    for (const auto& e : events) {
        e->displaydetails();
        cout << "----------------------------------------\n";
    }

    return 0;
}
