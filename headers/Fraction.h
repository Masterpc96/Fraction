//
// Created by Michael Urban on 24/12/2017.
//

#ifndef FRACTION_FRACTION_H
#define FRACTION_FRACTION_H


class Fraction {
private:
    int licznik;
    int mianownik;

public:
    // constructors and destructor
    Fraction(int licznik, int mianownik);

    Fraction (const Fraction& toCopy);

    Fraction (Fraction&& toMove);

    ~Fraction();

    // geters and setters
    int getLicznik() const;

    void setLicznik(int licznik);

    int getMianownik() const;

    void setMianownik(int mianownik);

    // operators

    Fraction& operator=(const Fraction &other); // copy

    Fraction& operator=(Fraction &&other); // move


    Fraction operator+(Fraction &other); // add

    Fraction &operator+=(Fraction &other); // add and equals

    Fraction operator-(Fraction &other); // sub

    Fraction &operator-=(Fraction &other); // sub and equals

    Fraction operator*(Fraction &other); // mult

    Fraction &operator*=(Fraction &other); // mult and equals

    Fraction operator/(Fraction &other); // div

    Fraction &operator/=(Fraction &other); // div and equals


    bool operator<(const Fraction &rhs) const;

    bool operator>(const Fraction &rhs) const;

    bool operator<=(const Fraction &rhs) const;

    bool operator>=(const Fraction &rhs) const;

    bool operator==(const Fraction &rhs) const;

    bool operator!=(const Fraction &rhs) const;


};


#endif //FRACTION_FRACTION_H
