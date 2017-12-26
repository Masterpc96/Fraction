#include <iostream>
#include "headers/Fraction.h"
int main() {


    Fraction fraction;
    Fraction fraction1(1,2);
    std::cout << "enter fraction" << std::endl;
    std::cin >> fraction;

    //--fraction;

    std::cout <<(fraction) << std::endl;
    return 0;
}