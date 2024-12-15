#include <iostream>
#include <stack>
#include <cctype>  // For isalnum() and tolower()
using namespace std;

// Function to preprocess the string
string preprocessString(const string& str) {
    string filtered;
    for (char ch : str) {
        if (isalnum(ch)) {
            filtered += tolower(ch);
        }
    }
    return filtered;
}

// Function to print the original and reversed string using a stack
void printReversedString(const string& str) {
    stack<char> stk;
    for (char ch : str) {
        stk.push(ch);
    }
    
    string reversed;
    while (!stk.empty()) {
        reversed += stk.top();
        stk.pop();
    }
    
    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reversed << endl;
}

// Function to check if the given string is a palindrome
bool isPalindrome(const string& str) {
    string filtered = preprocessString(str);
    string reversed(filtered.rbegin(), filtered.rend());
    return filtered == reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    
    // Print the original and reversed string
    printReversedString(input);
    
    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    return 0;
}
