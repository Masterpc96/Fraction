//
// Created by Michael Urban on 24/12/2017.
//

#ifndef FRACTION_FRACTION_H
#define FRACTION_FRACTION_H


#include <ostream>
#include <iostream>

class Fraction {
private:
    int licznik;
    int mianownik;

public:
    // constructors and destructor
    Fraction();

    Fraction(int licznik, int mianownik);

    // geters and setters
    int getLicznik() const;

    void setLicznik(int licznik);

    int getMianownik() const;

    void setMianownik(int mianownik);



    // operators

    Fraction operator+(Fraction &other); // add

    Fraction &operator+=(Fraction &other); // add and equals

    Fraction operator-(Fraction &other); // sub

    Fraction &operator-=(Fraction &other); // sub and equals

    Fraction operator*(Fraction &other); // mult

    Fraction &operator*=(Fraction &other); // mult and equals

    Fraction operator/(Fraction &other); // div

    Fraction &operator/=(Fraction &other); // div and equals


    Fraction &operator++(); // prefix increment
    Fraction operator++(int); // postfix increment
    Fraction &operator--(); // prefix decrement
    Fraction operator--(int); // postfix decrement


    bool operator<(const Fraction &rhs) const;

    bool operator>(const Fraction &rhs) const;

    bool operator<=(const Fraction &rhs) const;

    bool operator>=(const Fraction &rhs) const;

    bool operator==(const Fraction &rhs) const;

    bool operator!=(const Fraction &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);

    friend std::istream &operator>>(std::istream &, Fraction &fraction);
};
// own method

void reduce(Fraction &fraction);

#endif //FRACTION_FRACTION_H