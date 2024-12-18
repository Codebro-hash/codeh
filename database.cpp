#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

public:
    
    Student() : rollNumber(0), division('A') {}

    
    Student(string n, int r, string c, char d, string dob, string bg, string ca, string tn, string dl)
        : name(n), rollNumber(r), className(c), division(d), dateOfBirth(dob), bloodGroup(bg),
          contactAddress(ca), telephoneNumber(tn), drivingLicenseNo(dl) {}

    
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        className = s.className;
        division = s.division;
        dateOfBirth = s.dateOfBirth;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephoneNumber = s.telephoneNumber;
        drivingLicenseNo = s.drivingLicenseNo;
    }

    
    ~Student() {}

    
    void showDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
    }
};

int main() {
    
    Student *student1 = new Student("John Doe", 101, "10th", 'A', "01/01/2005", "O+", "123 Main St", "1234567890", "DL123456");
    
    
    student1->showDetails();

    
    Student *student2 = new Student(*student1);
    
    
    student2->showDetails();

    
    delete student1;
    delete student2;

    return 0;
}