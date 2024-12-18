
#include <iostream>
using namespace std;

class Publication {
protected:
    char title[50];
    float price;

public:
    Publication() {
        title[0] = '\0';
        price = 0.0;
    }

    void getData() {
        cout << "Enter title: ";
       // cin.ignore(); 
        cin.getline(title, 50);

        cout << "Enter price: ";
        cin >> price;
  
        if (cin.fail()) {
            cout << "Invalid input for price. Resetting values.\n";
            reset();
            cin.clear();             
            cin.ignore(10000, '\n');
        }
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    void reset() {
        title[0] = '\0';
        price = 0.0;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() {
        Publication::getData();

        cout << "Enter page count: ";
        cin >> pageCount;

        if (cin.fail()) {
            cout << "Invalid input for page count. Resetting values.\n";
            reset();
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    void display() const {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }

    void reset() {
        Publication::reset();
        pageCount = 0;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void getData() {
        Publication::getData();

        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;

        if (cin.fail()) {
            cout << "Invalid input for playing time. Resetting values.\n";
            reset();
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    void display() const {
        Publication::display();
        cout << "Playing Time (in minutes): " << playingTime << endl;
    }

    void reset() {
        Publication::reset();
        playingTime = 0.0;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for book:\n";
    book.getData();
    cout << "\nBook details:\n";
    book.display();

    cin.ignore(10000, '\n'); 

    cout << "\nEnter details for tape:\n";
    tape.getData();
    cout << "\nTape details:\n";
    tape.display();

    return 0;
}

