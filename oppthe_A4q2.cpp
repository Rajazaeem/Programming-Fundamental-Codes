#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Abstract base class
class BillingEntity {
protected:
    static int idCounter;
    int entityID;
    string name;

public:
    BillingEntity(string name) : name(name) {
        entityID = ++idCounter;
    }

    virtual double calculateBill() const = 0;

    virtual string getDetails() const {
        return "Entity ID: " + to_string(entityID) + "\nName: " + name;
    }

    virtual void saveToFile(ofstream& out) const {
        out << getDetails() << "\nBill: $" << calculateBill() << "\n----------------------\n";
    }

    virtual ~BillingEntity() {}
};

int BillingEntity::idCounter = 0;

// ================= Freelancer and Subclasses =================
class Freelancer : public BillingEntity {
public:
    Freelancer(string name) : BillingEntity(name) {}
};

class ProjectBasedFreelancer : public Freelancer {
    double ratePerProject;
    int numProjects;

public:
    ProjectBasedFreelancer(string name, double rate, int projects)
        : Freelancer(name), ratePerProject(rate), numProjects(projects) {}

    double calculateBill() const override {
        return ratePerProject * numProjects;
    }

    string getDetails() const override {
        return Freelancer::getDetails() +
               "\nType: Project-Based Freelancer\nProjects: " + to_string(numProjects) +
               "\nRate per Project: $" + to_string(ratePerProject);
    }
};

class HourlyBasedFreelancer : public Freelancer {
    double ratePerHour;
    int totalHours;

public:
    HourlyBasedFreelancer(string name, double rate, int hours)
        : Freelancer(name), ratePerHour(rate), totalHours(hours) {}

    double calculateBill() const override {
        if (totalHours <= 40)
            return totalHours * ratePerHour;
        else
            return (40 * ratePerHour) + ((totalHours - 40) * ratePerHour * 1.5);
    }

    string getDetails() const override {
        return Freelancer::getDetails() +
               "\nType: Hourly-Based Freelancer\nHours: " + to_string(totalHours) +
               "\nRate per Hour: $" + to_string(ratePerHour);
    }
};

// ================= Energy Consumer and Subclasses =================
class EnergyConsumer : public BillingEntity {
public:
    EnergyConsumer(string name) : BillingEntity(name) {}
};

class Lab : public EnergyConsumer {
    int computers;
    int avgUsageHours;

public:
    Lab(string name, int computers, int hours)
        : EnergyConsumer(name), computers(computers), avgUsageHours(hours) {}

    double calculateBill() const override {
        return computers * avgUsageHours * 0.2; // Assume 0.2 per hour per computer
    }

    string getDetails() const override {
        return EnergyConsumer::getDetails() +
               "\nType: Lab\nComputers: " + to_string(computers) +
               "\nAvg Usage (hrs): " + to_string(avgUsageHours);
    }
};

class Cafeteria : public EnergyConsumer {
    string equipmentType;
    int hoursUsed;

public:
    Cafeteria(string name, string equipment, int hours)
        : EnergyConsumer(name), equipmentType(equipment), hoursUsed(hours) {}

    double calculateBill() const override {
        double rate = (equipmentType == "Oven") ? 1.5 : 1.0; 
        return hoursUsed * rate * 2.0;
    }

    string getDetails() const override {
        return EnergyConsumer::getDetails() +
               "\nType: Cafeteria\nEquipment: " + equipmentType +
               "\nUsage Hours: " + to_string(hoursUsed);
    }
};

// ================= Main Function =================
int main() {
    vector<BillingEntity*> entities;

    entities.push_back(new ProjectBasedFreelancer("Alice", 500, 4));
    entities.push_back(new HourlyBasedFreelancer("Bob", 20, 45));
    entities.push_back(new Lab("AI Lab", 30, 8));
    entities.push_back(new Cafeteria("Main Cafe", "Oven", 10));

    ofstream out("billing.txt");

    for (auto* e : entities) {
        cout << e->getDetails() << "\nBill: $" << e->calculateBill() << "\n----------------------\n";
        e->saveToFile(out);
        delete e; // clean up
    }

    out.close();
    return 0;
}