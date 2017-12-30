//
// Created by Michael Urban on 24/12/2017.
//



#include "../headers/Fraction.h"
//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MODULE fraction
//
//#include <boost/test/unit_test.hpp>

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
    int a = abs(fraction.getLicznik());
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
    licznik *=  other.mianownik;
    mianownik *= other.licznik;
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

Fraction::operator int() {
    return licznik/mianownik;
}

Fraction::operator double() {
    return (double)licznik/mianownik;
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
    if (pos == std::string::npos) {
        fraction.licznik = std::stoi(input);
        fraction.mianownik = 1;
    } else {
        fraction.licznik = std::stoi(input.substr(0, pos));
        fraction.mianownik = std::stoi(input.substr(pos + 1));
        if (fraction.mianownik == 0) throw std::invalid_argument("Denominator cannot be ZERO");

        if(fraction.mianownik < 0) {
            fraction.licznik = - fraction.licznik;
            fraction.mianownik = - fraction.mianownik;
        }
        reduce(fraction);
    }

    return in;
} // input with /



//BOOST_AUTO_TEST_SUITE(Relational)
//
//    BOOST_AUTO_TEST_CASE(bigger) {
//        Fraction a(1, 8);
//        Fraction b(1, 12);
//        BOOST_CHECK(a < b == false);
//
//
//        Fraction c(5, 8);
//        Fraction d(10, 8);
//        BOOST_CHECK(c < d == true);
//
//
//        Fraction e(5, 8);
//        Fraction f(10, 12);
//        BOOST_CHECK(e < f == true);
//    }
//
//    BOOST_AUTO_TEST_CASE(less) {
//        Fraction a(1, 8);
//        Fraction b(1, 12);
//        BOOST_CHECK(a > b == true);
//
//
//        Fraction c(5, 8);
//        Fraction d(10, 8);
//        BOOST_CHECK(c > d == false);
//
//
//        Fraction e(5, 8);
//        Fraction f(10, 12);
//        BOOST_CHECK(e > f == false);
//    }
//
//    BOOST_AUTO_TEST_CASE(biggerOrEquals) {
//        Fraction a(1, 8);
//        Fraction b(1, 12);
//        BOOST_CHECK(a <= b == false);
//
//
//        Fraction c(2, 8);
//        Fraction d(2, 8);
//        BOOST_CHECK(c <= d == true);
//    }
//
//    BOOST_AUTO_TEST_CASE(lessOrEquals) {
//        Fraction a(1, 12);
//        Fraction b(1, 8);
//        BOOST_CHECK(a <= b == true);
//
//
//        Fraction c(2, 8);
//        Fraction d(2, 8);
//        BOOST_CHECK(c <= d == true);
//    }
//
//    BOOST_AUTO_TEST_CASE(equals) {
//        Fraction a(1, 8);
//        Fraction b(1, 12);
//        BOOST_CHECK((a == b) == false);
//
//
//        Fraction c(2, 8);
//        Fraction d(2, 8);
//        BOOST_CHECK((c == d) == true);
//    }
//
//    BOOST_AUTO_TEST_CASE(notEquals) {
//        Fraction a(1, 8);
//        Fraction b(1, 12);
//        BOOST_CHECK((a != b) == true);
//
//
//        Fraction c(2, 8);
//        Fraction d(2, 8);
//        BOOST_CHECK((c != d) == false);
//    }
//
//BOOST_AUTO_TEST_SUITE_END()
//
//
//BOOST_AUTO_TEST_SUITE(NWD)
//
//    BOOST_AUTO_TEST_CASE(bigger) {
//        Fraction a(5, -100);
//        reduce(a);
//        BOOST_CHECK(a.getLicznik() == -1);
//        BOOST_CHECK(a.getMianownik() == 20);
//    }
//
//BOOST_AUTO_TEST_SUITE_END()
//
//
//BOOST_AUTO_TEST_SUITE(streams)
//
//    BOOST_AUTO_TEST_CASE(input) {
//        Fraction a;
//        std::istringstream toConvert;
//        std::string frac("1/2");
//        toConvert.str(frac);
//
//        toConvert >> a;
//
//        BOOST_CHECK(a.getLicznik() == 1);
//        BOOST_CHECK(a.getMianownik() == 2);
//    }
//
//    BOOST_AUTO_TEST_CASE(output) {
//        Fraction a(2, 5);
//        std::ostringstream os;
//        os << a;
//
//        std::string frac = os.str();
//
//        BOOST_CHECK(frac == "2/5");
//    }
//
//BOOST_AUTO_TEST_SUITE_END()
//
//BOOST_AUTO_TEST_SUITE(Matematyka)
//
//    BOOST_AUTO_TEST_CASE(testInt) {
//        Fraction a(4, 3);
//        BOOST_CHECK((static_cast<int>(a)) == 1);
//    }
//
//    BOOST_AUTO_TEST_CASE(testDouble) {
//        Fraction a(1, 2);
//        BOOST_CHECK((static_cast<double>(a)) == 0.5);
//    }
//
//
//    BOOST_AUTO_TEST_CASE(testAdd) {
//        Fraction a(2, 3);
//        Fraction b(4, 3);
//        Fraction c(1, 2);
//        c += b;
//        BOOST_CHECK(a + b == Fraction(2));
//        BOOST_CHECK(c == Fraction(11, 6));
//    }
//
//    BOOST_AUTO_TEST_CASE(testSub) {
//        Fraction a(2, 3);
//        Fraction b(4, 3);
//        Fraction c(1, 2);
//        c -= b;
//        BOOST_CHECK(a - b == Fraction(-2, 3));
//        BOOST_CHECK(c == Fraction(-5, 6));
//    }
//
//    BOOST_AUTO_TEST_CASE(testMult) {
//        Fraction a(2, 3);
//        Fraction b(4, 3);
//        Fraction c(1, 2);
//        c *= b;
//        BOOST_CHECK(a * b == Fraction(8, 9));
//        BOOST_CHECK(c == Fraction(2, 3));
//    }
//
//    BOOST_AUTO_TEST_CASE(testDiv) {
//        Fraction a(2, 3);
//        Fraction b(4, 3);
//        Fraction c(1, 2);
//        c /= b;
//        BOOST_CHECK(a / b == Fraction(1, 2));
//        BOOST_CHECK(c == Fraction(3, 8));
//    }
//
//BOOST_AUTO_TEST_SUITE_END()
//
