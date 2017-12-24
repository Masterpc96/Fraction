//
// Created by Michael Urban on 24/12/2017.
//


/**************** NOT TESTED ****************/

#include "../headers/Fraction.h"

// constructors and destructor
Fraction::Fraction(int licznik, int mianownik) : licznik(licznik), mianownik(mianownik) {}

Fraction::Fraction(const Fraction &toCopy) : licznik(toCopy.licznik), mianownik(toCopy.mianownik) {}

Fraction::Fraction(Fraction &&toMove) : licznik(toMove.licznik), mianownik(toMove.mianownik) {
    toMove.licznik = 0;
    toMove.mianownik = 0;
}

Fraction::~Fraction() {

}


// getters and setters
int Fraction::getLicznik() const {
    return licznik;
}

void Fraction::setLicznik(int licznik) {
    Fraction::licznik = licznik;
}

int Fraction::getMianownik() const {
    return mianownik;
}

void Fraction::setMianownik(int mianownik) {
    Fraction::mianownik = mianownik;
}

// operators
Fraction &Fraction::operator=(const Fraction &other) {
    licznik = other.licznik;
    mianownik = other.mianownik;
    return *this;
} // done

Fraction &Fraction::operator=(Fraction &&other) {
    licznik = other.licznik;
    other.licznik = 0;

    mianownik = other.mianownik;
    other.mianownik = 0;
    return *this;
} // done


Fraction Fraction::operator+(Fraction &other) {
    Fraction temp(licznik * other.mianownik + other.licznik * mianownik, mianownik * other.mianownik);
    return temp;
} // done

Fraction &Fraction::operator+=(Fraction &other) {
    licznik = licznik * other.mianownik + other.licznik * mianownik;
    mianownik *= other.mianownik;
    return *this;
} // done

Fraction Fraction::operator-(Fraction &other) {
    Fraction temp(licznik * other.mianownik - other.licznik * mianownik, mianownik * other.mianownik);
    return temp;
} // done

Fraction &Fraction::operator-=(Fraction &other) {
    licznik = licznik * other.mianownik + other.licznik * mianownik;
    mianownik *= other.mianownik;
    return *this;
} // done

Fraction Fraction::operator*(Fraction &other) {
    Fraction temp(licznik * other.licznik, mianownik * other.mianownik);
    return temp;
} // done

Fraction &Fraction::operator*=(Fraction &other) {
    licznik *= other.licznik;
    mianownik *= other.mianownik;
    return *this;
} // done

Fraction Fraction::operator/(Fraction &other) {
    Fraction temp(licznik * other.mianownik, mianownik * other.mianownik);
    return temp;
} // done

Fraction &Fraction::operator/=(Fraction &other) {
    licznik *= mianownik;
    mianownik *= licznik;
    return *this;
} // done


bool Fraction::operator<(const Fraction &other) const {
    if (mianownik == other.mianownik) {
        return licznik < other.licznik;

    } else if (licznik == other.licznik) {
        return mianownik > other.mianownik;

    } else {
        return ((licznik * other.mianownik) < (other.licznik * mianownik));
    }
} // done

bool Fraction::operator>(const Fraction &other) const {
    if (mianownik == other.mianownik) {
        return licznik > other.licznik;

    } else if (licznik == other.licznik) {
        return mianownik < other.mianownik;

    } else {
        return ((licznik * other.mianownik) > (other.licznik * mianownik));
    }
} // done

bool Fraction::operator<=(const Fraction &other) const {
    return !(*this > other);
} // done

bool Fraction::operator>=(const Fraction &other) const {
    return !(*this < other);

} // done

bool Fraction::operator==(const Fraction &other) const {
    return licznik == other.licznik &&
           mianownik == other.mianownik;
} // done

bool Fraction::operator!=(const Fraction &other) const {
    return !(other == *this);
} // done
