#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    char name[30];
    int marks;

void getdata() {
    cout << "\nEnter Student's Details-->" << endl;
    cout << "Enter roll no: ";
    cin >> roll;
    cin.ignore(); // Clear the newline character from the input buffer
    cout << "Enter Student's name: ";
    cin.getline(name, 30);
    cout << "Enter marks: ";
    cin >> marks;
}

void displaydata() {
    cout << "\nRoll No: " << roll << endl;
    cout << "Student's Name: " << name << endl;
    cout << "Student's Marks: " << marks << endl;
}
};

int main() {
    Student s[70];
    fstream file;
    int n;
   
    file.open("xyz.txt", ios::out | ios::binary);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << "Enter Number of Students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        s[i].getdata();
        file.write((char*)&s[i], sizeof(s[i]));
    }
    file.close();

    
    file.open("xyz.txt", ios::in | ios::binary);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nReading Student information from the file..." << endl;

    for (int i = 0; i < n; i++) {
        file.read((char*)&s[i], sizeof(s[i]));
        s[i].displaydata();
    }

    file.close();
    return 0;
}