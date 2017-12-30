
#include <iostream>
#include "headers/Fraction.h"
#include "headers/OnpCalculator.h"

using namespace std;


int main() {
    int choice = 0;
    std::string input;
    std::cout << "Welcome in ONP calculator, please select on which data would you like to work\n"
            "1. Int\n"
            "2. Double\n"
            "3. Fractions" << std::endl;
    std::cin >> choice;

    std::cout << "Enter fraze to calculate each symbol must be seperate by SPACEBAR \neg. 1 1 +" << endl;

    std::cin.ignore();

    getline(std::cin, input); // reading fraze from console

    if (choice == 1) {
        std::cout << onpCalculator<int>(input) << std::endl;
    } else if (choice == 2) {
        std::cout << onpCalculator<double>(input) << std::endl;
    } else if (choice == 3) {
        std::cout << onpCalculator<Fraction>(input) << std::endl;
    }
    return 0;

}
