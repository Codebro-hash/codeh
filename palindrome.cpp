#include<iostream>
#include<string.h>
#define max 50
using namespace std;

class STACK {
    private:
        char a[max];
        int top;

    public:
        STACK() {
            top = -1;
        }

        void push(char);
        void reverse();
        void convert(char[]);
        void palindrome();
};

void STACK::push(char c) {
    top++;
    a[top] = c;
    a[top+1]='\0';
    //cout<<endl<<c<<" is pushed on stack...";
}

void STACK::reverse() {
    char str[max];
    int j = 0;
    
    for(int i = top; i >= 0; i--) {
        cout<<a[i];
        str[j] = a[i];
        j++;
    }
    
    str[j] = '\0';
    cout << "\n\nReverse string is: " << str << endl;
}

void STACK::convert(char str[]) {
    int j, k;
    int len = strlen(str);
    for(j = 0, k = 0; j < len; j++) {
        if((str[j] >= 97 && str[j] <= 122) || (str[j] >= 65 && str[j] <= 90)) {
            if(str[j] <= 90 && str[j] >= 65) {
                str[k] = str[j] + 32;
            } else {
                str[k] = str[j];
            }
            k++;
        }
    }

    str[k] = '\0';
    cout << endl << "Converted String: " << str << "\n";
}

void STACK::palindrome() {
    char str[max];
    int i, j;

    for(i = top, j = 0; i >= 0; i--, j++) {
        str[j] = a[i];
    }

    str[j] = '\0';

    if(strcmp(str, a) == 0) {
        cout << "\n\nString is a palindrome...";
    } else {
        cout << "\n\nString is not a palindrome...";
    }
}

int main() {
    STACK s;
    char inputStr[max];
    
    cout << "Enter a string: ";
    cin >> inputStr;
    
    s.convert(inputStr);
    
    for(int i = 0; inputStr[i] != '\0'; i++) {
        s.push(inputStr[i]);
    }

    s.reverse();
    s.palindrome();

    return 0;
}