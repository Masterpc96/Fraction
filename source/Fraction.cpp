//
// Created by Michael Urban on 24/12/2017.
//


/**************** NOT TESTED ****************/

#include "../headers/Fraction.h"

// constructors
Fraction::Fraction() {};

Fraction::Fraction(int licznik, int mianownik) : licznik(licznik), mianownik(mianownik) {
    if (mianownik < 0) {
        this->licznik = -this->licznik;
        this->mianownik = -this->mianownik;
    }
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
    Fraction temp(licznik * other.mianownik, mianownik * other.licznik);
    if (temp.mianownik < 0) {
        temp.licznik = -temp.licznik;
        temp.mianownik = -temp.mianownik;
    }
    return temp;
} // done

Fraction &Fraction::operator/=(Fraction &other) {
    licznik *= mianownik;
    mianownik *= licznik;
    if (mianownik < 0) {
        licznik = -licznik;
        mianownik = -mianownik;
    }
    return *this;
} // done

Fraction &Fraction::operator++() {
    licznik += mianownik;
    return *this;
} // pre and done

Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    licznik += mianownik;
    return temp;
} // post and done

Fraction &Fraction::operator--() {
    licznik -= mianownik;
    return *this;
} // done

Fraction Fraction::operator--(int) {
    Fraction temp(*this);
    licznik -= mianownik;
    return temp;
}


bool Fraction::operator<(const Fraction &other) const {
    if (mianownik == other.mianownik || licznik == -other.licznik) {
        return licznik < other.licznik;

    } else if (licznik == other.licznik) {
        return mianownik > other.mianownik;

    } else {
        return ((licznik * other.mianownik) < (other.licznik * mianownik));
    }
} // done

bool Fraction::operator>(const Fraction &other) const {
    if (mianownik == other.mianownik || licznik == -other.licznik) {
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

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    os << fraction.licznik << "/" << fraction.mianownik;
    return os;
} // done

//std::istream &operator>>(std::istream &in, Fraction &fraction) {
//    in >> fraction.licznik >> fraction.mianownik;
//    return in;
//} // input number by number

std::istream &operator>>(std::istream &in, Fraction &fraction) {
    std::string input;
    in >> input;
    std::size_t pos = input.find('/');
    fraction.licznik = std::stoi(input.substr(0, pos));
    fraction.mianownik = std::stoi(input.substr(pos + 1));

    return in;
} // input with /

// done