#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

class KnowledgeResource
{
private:
    int resourceID;
    string title;
    string department;
    static int nextResourceID;

public:
    // Default constructor
    KnowledgeResource() : resourceID(generateResourceID()), title("Unknown"), department("Unknown") {}

    // Parameterized constructor
    KnowledgeResource(const string &title, const string &department)
        : resourceID(generateResourceID()), title(title), department(department) {}

    // Getter methods
    int getResourceID() const { return resourceID; }
    string getTitle() const { return title; }
    string getDepartment() const { return department; }

    // Virtual function to display details
    virtual void getDetails() const
    {
        cout << "\n------Details of Resource------" << endl;
        cout << "Resource ID: " << resourceID << endl;
        cout << "Title: " << title << endl;
        cout << "Department: " << department << endl;
    }

    // Function to save object details to a file
    void saveToFile() const
    {
        ofstream outfile("resources.txt", ios::app); // Open in append mode
        if (outfile.is_open())
        {
            // Redirect cout to the file
            streambuf *cout_sbuf = cout.rdbuf(); // Save cout's buffer
            cout.rdbuf(outfile.rdbuf());         // Redirect cout to file

            getDetails();

            cout.rdbuf(cout_sbuf); // Restore cout's original buffer
            outfile.close();
            cout << "Resource saved to file." << endl;
        }
        else
        {
            cout << "Unable to open file for saving." << endl;
        }
    }

    // Function to read and display all records from the file
    static void readFromFile()
    {
        ifstream infile("resources.txt");
        string line;
        if (infile.is_open())
        {
            cout << "\n--- Resources from file: ---" << endl;
            while (getline(infile, line))
            {
                cout << line << endl;
            }
            infile.close();
        }
        else
        {
            cout << "Unable to open file for reading." << endl;
        }
    }

private:
    // Helper function to generate unique resource IDs
    int generateResourceID()
    {
        return nextResourceID++;
    }
};

// Initialize the static member
int KnowledgeResource::nextResourceID = 1;

// Overload the << operator for KnowledgeResource
ostream &operator<<(ostream &os, const KnowledgeResource &resource)
{
    resource.getDetails();
    return os;
}

class EBook : public KnowledgeResource
{
private:
    string author;
    double fileSizeMB;

public:
    // Default constructor
    EBook() : author("Unknown"), fileSizeMB(0.0), KnowledgeResource() {}

    // Parameterized constructor
    EBook(const string &title, const string &department, const string &author, double fileSizeMB)
        : KnowledgeResource(title, department), author(author), fileSizeMB(fileSizeMB) {}

    // Getter methods
    string getAuthor() const { return author; }
    double getFileSizeMB() const { return fileSizeMB; }

    // Override getDetails()
    void getDetails() const override
    {
        KnowledgeResource::getDetails();
        cout << "Author: " << author << endl;
        cout << fixed << setprecision(2);
        cout << "File Size (MB): " << fileSizeMB << endl;
    }
};

class PrintedJournal : public KnowledgeResource
{
private:
    string publisher;
    int volume;

public:
    // Default constructor
    PrintedJournal() : publisher("Unknown"), volume(0), KnowledgeResource() {}

    // Parameterized constructor
    PrintedJournal(const string &title, const string &department, const string &publisher, int volume)
        : KnowledgeResource(title, department), publisher(publisher), volume(volume) {}

    // Getter methods
    string getPublisher() const { return publisher; }
    int getVolume() const { return volume; }

    // Override getDetails()
    void getDetails() const override
    {
        KnowledgeResource::getDetails();
        cout << "Publisher: " << publisher << endl;
        cout << "Volume: " << volume << endl;
    }
};

// Template class for Resource Collection
template <typename T>
class ResourceCollection
{
private:
    vector<T> resources;

public:
    void addResource(const T &resource)
    {
        resources.push_back(resource);
    }

    void displayAllResources() const
    {
        cout << "\n--- All Resources in Collection: ---" << endl;
        for (const auto &resource : resources)
        {
            cout << resource; // Uses the overloaded << operator
        }
    }

    // Add a method to access the resources vector (for cleanup)
    vector<T> &getResources()
    {
        return resources;
    }
};

// Function to clear the input buffer
void clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    ResourceCollection<KnowledgeResource *> myCollection;
    int choice;

    do
    {
        cout << "\n--- Knowledge Resource Management System ---" << endl;
        cout << "1. Add EBook" << endl;
        cout << "2. Add Printed Journal" << endl;
        cout << "3. Read Resources from File" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        // Validate input
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            clearInputBuffer();
            choice = -1;        // Force loop to continue
            continue;
        }
        clearInputBuffer(); // Consume the newline character

        switch (choice)
        {
        case 1:
        {
            string title, department, author;
            double fileSizeMB;

            cout << "Enter EBook Title: ";
            getline(cin, title);
            cout << "Enter Department: ";
            getline(cin, department);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter File Size (MB): ";
            cin >> fileSizeMB;
            clearInputBuffer();

            if (cin.fail())
            {
                cout << "Invalid file size. Please enter a number." << endl;
                cin.clear();
                clearInputBuffer();
                break;
            }

            EBook *newEBook = new EBook(title, department, author, fileSizeMB);
            myCollection.addResource(newEBook);
            newEBook->saveToFile();
            break;
        }
        case 2:
        {
            string title, department, publisher;
            int volume;

            cout << "Enter Journal Title: ";
            getline(cin, title);
            cout << "Enter Department: ";
            getline(cin, department);
            cout << "Enter Publisher: ";
            getline(cin, publisher);
            cout << "Enter Volume: ";
            cin >> volume;
            clearInputBuffer();

            if (cin.fail())
            {
                cout << "Invalid volume. Please enter a number." << endl;
                cin.clear();
                clearInputBuffer();
                break;
            }

            PrintedJournal *newJournal = new PrintedJournal(title, department, publisher, volume);
            myCollection.addResource(newJournal);
            newJournal->saveToFile();
            break;
        }
        case 3:
            KnowledgeResource::readFromFile();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    // Iterate through the collection and delete each resource
    vector<KnowledgeResource *> &resources = myCollection.getResources();
    for (size_t i = 0; i < resources.size(); ++i)
    {
        delete resources[i];
    }
    resources.clear(); // Clear the vector after deleting

    return 0;
}