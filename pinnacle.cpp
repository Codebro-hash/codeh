#include <iostream>
#include <string>
using namespace std;

struct Node {
    int PRN;                  // Student's PRN
    string name;              // Student's name
    Node* next;               // Pointer to the next node

    Node(int prn, string n) : PRN(prn), name(n), next(nullptr) {} // Constructor
};

class PinnacleClub {
private:
    Node* head;  // Pointer to the president (first node)
    Node* tail;  // Pointer to the secretary (last node)

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    // Add member
    void addMember(int prn, string name, string position = "member") {
        Node* newNode = new Node(prn, name);

        if (position == "president") {
            // Add as president
            newNode->next = head;
            head = newNode;
            if (!tail) tail = head; // If the list was empty, update tail
        } else if (position == "secretary") {
            // Add as secretary
            if (!tail) {
                head = tail = newNode; // If the list is empty
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        } else {
            // Add as regular member
            if (!head) {
                head = tail = newNode; // If the list is empty
            } else {
                newNode->next = head->next;
                head->next = newNode;
            }
        }
    }

    // Delete member
    void deleteMember(int prn) {
        if (!head) {
            cout << "The list is empty.\n";
            return;
        }

        if (head->PRN == prn) { // Delete president
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head) tail = nullptr; // If the list becomes empty
            return;
        }

        Node* current = head;
        while (current->next && current->next->PRN != prn) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) tail = current; // Update tail if secretary is deleted
            delete temp;
        } else {
            cout << "PRN not found.\n";
        }
    }

    // Compute total number of members
    int countMembers() const {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Display members
    void displayMembers() const {
        if (!head) {
            cout << "The list is empty.\n";
            return;
        }

        Node* current = head;
        cout << "Club Members:\n";
        while (current) {
            cout << "PRN: " << current->PRN << ", Name: " << current->name;
            if (current == head) cout << " (President)";
            else if (current == tail) cout << " (Secretary)";
            cout << "\n";
            current = current->next;
        }
    }

    // Concatenate two lists
    void concatenate(PinnacleClub& other) {
        if (!other.head) return; // If the other list is empty, do nothing

        if (!head) { // If this list is empty, set it to the other list
            head = other.head;
            tail = other.tail;
        } else { // Otherwise, append the other list to this one
            tail->next = other.head;
            tail = other.tail;
        }

        other.head = nullptr;
        other.tail = nullptr; // Clear the other list
    }

    ~PinnacleClub() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function for testing
int main() {
    PinnacleClub divA, divB;

    // Add members to Division A
    divA.addMember(1, "Ram", "president");
    divA.addMember(2, "Sham");
    divA.addMember(3, "Om", "secretary");

    // Add members to Division B
    divB.addMember(4, "Rutik", "president");
    divB.addMember(5, "Raj");
    divB.addMember(6, "Sarthak", "secretary");

    // Display members of Division A
    cout << "Division A:\n";
    divA.displayMembers();

    // Display members of Division B
    cout << "\nDivision B:\n";
    divB.displayMembers();

    // Concatenate Division B into Division A
    cout << "\nConcatenating Division B into Division A...\n";
    divA.concatenate(divB);

    // Display members of concatenated list
    cout << "\nAfter Concatenation - Division A:\n";
    divA.displayMembers();

    // Count total members in Division A
    cout << "\nTotal Members in Division A: " << divA.countMembers() << "\n";

    return 0;
}
