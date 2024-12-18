
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    
    Complex(double r = 0.0, double i = 0.0){
      real = r;
      imag = i;
    }

    
    Complex operator+(const Complex& c) const {
        double result_r = real + c.real;
        double result_i = imag + c.imag;
        return Complex( result_r,result_i );
    }

    
    Complex operator*(const Complex& c) const {
        double realPart = (real * c.real) - (imag * c.imag);
        double imagPart = (real * c.imag) + (imag * c.real);
        return Complex(realPart, imagPart);
    }

    
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2, sum, product;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    sum = c1 + c2;
    product = c1 * c2;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}

