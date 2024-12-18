#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:
    int code;
    string name;
    string dob; // Date of Birth in format YYYY-MM-DD 
    string telephone;

    Person(int c, string n, string d, string t) : code(c), name(n), dob(d), telephone(t) {}

    void display() const {
        cout << "Code: " << code << ", Name: " << name << ", DOB: " << dob << ", Telephone: " << telephone << endl;
    }
 
    bool operator < (const Person& other) const {
        return code < other.code;
    }
};

int main() {
    vector<Person> people = {
        {101, "Arnav", "1995-08-17", "1234567890"},
        {102, "Babu", "1992-05-24", "2345678901"},
        {103, "Chetan", "1989-11-30", "3456789012"}
    };

    cout << "People before sorting:" << endl;
    for (const auto& person : people) {
        person.display();
    }

    sort(people.begin(), people.end());

    cout << "\nPeople after sorting:" << endl;
    for (const auto& person : people) {
        person.display();
    }

    int searchCode;
    cout << "\nEnter person code to search: ";
    cin >> searchCode;
    auto it = find_if(people.begin(), people.end(), [searchCode](const Person& person) {
        return person.code == searchCode; 
    });

    if (it != people.end()) {
        cout << "Person found: ";
        it->display();
    } else {
        cout << "Person with code " << searchCode << " not found." << endl;
    }

    return 0;
}
