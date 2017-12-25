#include <iostream>
#include "headers/Fraction.h"
int main() {


    Fraction fraction;
    Fraction fraction1(2,5);
    std::cout << "enter fraction" << std::endl;
    std::cin >> fraction;

    //--fraction;

    std::cout << (fraction < fraction1) << std::endl;
    return 0;
}