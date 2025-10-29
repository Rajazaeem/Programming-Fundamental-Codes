#include <iostream>
#include <string>

using namespace std;

class student {
private:
    string name;
    int age;
    int rollno;

public:
    void set_student_details(const string& n, int a, int r) {
        name = n;
        age = a;
        rollno = r;
    }

    string get_name() const { return name; }
    int get_age() const { return age; }
    int get_rollno() const { return rollno; }

    void input_student() {
        string n;
        int a, r;
        cout << "Enter the name of the student: ";
        cin >> n;
        cout << "Enter the age of the student: ";
        cin >> a;
        cout << "Enter the roll number of the student: ";
        cin >> r;

        set_student_details(n, a, r);
    }

    void display_student() const {
        cout << "Student Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollno << endl;
    }
};

class exam : virtual public student {
private:
    float exam_result;

public:
    void set_exam_details(float result) {
        exam_result = result;
    }

    float get_exam_result() const { return exam_result; }

    void input_exam() {
        float result;
        cout << "Enter the exam result: ";
        cin >> result;
        set_exam_details(result);
    }

    void display_exam() const {
        cout << "Exam Result: " << exam_result << endl;
    }
};

class sport : virtual public student {
private:
    float sport_marks;

public:
    void set_sport_details(float marks) {
        sport_marks = marks;
    }

    float get_sport_marks() const { return sport_marks; }

    void input_sport() {
        float marks;
        cout << "Enter the sport marks: ";
        cin >> marks;
        set_sport_details(marks);
    }

    void display_sport() const {
        cout << "Sport Marks: " << sport_marks << endl;
    }
};

class result : public exam, public sport {
public:
    void input_all() {
        input_student();
        input_exam();
        input_sport();
    }

    void display_all() const {
        display_student();
        display_exam();
        display_sport();
        float total = get_exam_result() + get_sport_marks();
        cout << "Total Marks (Exam + Sports): " << total << endl;
    }
};

int main() {
    result r;
    r.input_all();

    cout << "\n--- Student Report ---" << endl;
    r.display_all();

    return 0;
}