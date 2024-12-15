#include <iostream>
#include <string>
using namespace std;

// Function to check if the given expression is well-parenthesized
bool isWellParenthesized(const string& expression) {
    char stack[1000];
    int top = -1;

    // Iterate through each character in the expression
    for (char ch : expression) {
        // Push opening delimiters onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        // Check closing delimiters
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If the stack is empty or does not match, return false
            if (top == -1 || 
                (ch == ')' && stack[top] != '(') ||
                (ch == '}' && stack[top] != '{') ||
                (ch == ']' && stack[top] != '[')) {
                return false;
            }
            // Pop the matching opening delimiter
            top--;
        }
    }

    // If the stack is empty, the expression is well-parenthesized
    return top == -1;
}

int main() {
    string expression;

    // Input the expression from the user
    cout << "Enter an expression: ";
    getline(cin, expression);

    // Check if the expression is well-parenthesized
    if (isWellParenthesized(expression)) {
        cout << "The expression is well parenthesized." << endl;
    } else {
        cout << "The expression is not well parenthesized." << endl;
    }

    return 0;
}