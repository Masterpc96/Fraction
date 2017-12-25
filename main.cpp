#include <iostream>
#include "headers/Fraction.h"
using namespace std;
int main() {


    Fraction fraction;
    std::cout << "enter fraction" << std::endl;
    std::cin >> fraction;

    --fraction;

    std::cout << fraction << std::endl;
    return 0;
}