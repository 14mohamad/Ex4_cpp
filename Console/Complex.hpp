#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
    double real;
    double imag;

    // בנאי ברירת מחדל המאתחל את המספר המרוכב ל- (0, 0)
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // מחזירה את הסכום של המספר המרוכב הנוכחי ואחר
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // מחזירה את ההפרש בין המספר המרוכב הנוכחי לאחר
    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    //בודק אם המספר המרוכב הנוכחי שווה לאחר
    bool operator==(const Complex &other) const
    {
        return real == other.real && imag == other.imag;
    }

    // עומס יתר על האופרטור << כדי לאפשר פלט של המספר המרוכב לזרם פלט
    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }
};

#endif // COMPLEX_H
