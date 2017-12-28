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
    reduce(*this);
}

Fraction::Fraction(int licznik) : licznik(licznik), mianownik(1) {
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

// own method

void reduce(Fraction &fraction) {
    int pom;
    int a = fraction.getLicznik();
    int b = fraction.getMianownik();
    while (b != 0) {
        pom = b;
        b = a % b;
        a = pom;
    }

    fraction.setLicznik(fraction.getLicznik() / a);
    fraction.setMianownik(fraction.getMianownik() / a);
}

// operators

Fraction Fraction::operator+(Fraction &other) {
    Fraction temp(licznik * other.mianownik + other.licznik * mianownik, mianownik * other.mianownik);
    reduce(temp);
    return temp;
} // done

Fraction &Fraction::operator+=(Fraction &other) {
    licznik = licznik * other.mianownik + other.licznik * mianownik;
    mianownik *= other.mianownik;
    reduce(*this);
    return *this;
} // done

Fraction Fraction::operator-(Fraction &other) {
    Fraction temp(licznik * other.mianownik - other.licznik * mianownik, mianownik * other.mianownik);
    reduce(temp);
    return temp;
} // done

Fraction &Fraction::operator-=(Fraction &other) {
    licznik = licznik * other.mianownik - other.licznik * mianownik;
    mianownik *= other.mianownik;
    reduce(*this);
    return *this;
} // done

Fraction Fraction::operator*(Fraction &other) {
    Fraction temp(licznik * other.licznik, mianownik * other.mianownik);
    reduce(temp);
    return temp;
} // done

Fraction &Fraction::operator*=(Fraction &other) {
    licznik *= other.licznik;
    mianownik *= other.mianownik;
    reduce(*this);
    return *this;
} // done

Fraction Fraction::operator/(Fraction &other) {
    Fraction temp(licznik * other.mianownik, mianownik * other.licznik);
    if (temp.mianownik < 0) {
        temp.licznik = -temp.licznik;
        temp.mianownik = -temp.mianownik;
    }
    reduce(temp);
    return temp;
} // done

Fraction &Fraction::operator/=(Fraction &other) {
    licznik *= mianownik;
    mianownik *= licznik;
    if (mianownik < 0) {
        licznik = -licznik;
        mianownik = -mianownik;
    }
    reduce(*this);
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
} //done


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
    if (fraction.mianownik == 1) {
        os << fraction.licznik;
    } else {
        os << fraction.licznik << "/" << fraction.mianownik;
    }
    return os;
} // done

//std::istream &operator>>(std::istream &in, Fraction &fraction) {
//    in >> fraction.licznik >> fraction.mianownik;
//    reduce(fraction);
//    return in;
//} // input number by number

std::istream &operator>>(std::istream &in, Fraction &fraction) {
    std::string input;
    in >> input;
    std::size_t pos = input.find('/');
    if(pos == std::string::npos){
        fraction.licznik = std::stoi(input);
        fraction.mianownik = 1;
    }else{
        fraction.licznik = std::stoi(input.substr(0, pos));
        fraction.mianownik = std::stoi(input.substr(pos + 1));
        if(fraction.mianownik == 0) throw std::invalid_argument("Denominator cannot be ZERO");
        reduce(fraction);
    }

    return in;
} // input with /

// done