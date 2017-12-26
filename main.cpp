#include <iostream>
#include <stack>
#include "headers/MyStack.h"
#include "headers/Fraction.h"

int main() {


    MyStack <Fraction>stack;

    for (Fraction i(1,2); i < Fraction(10,1); i++) {
        stack.push(i);
    }

    while (!stack.isEmpty()){
        std::cout << stack.pop()<< std::endl;
    }

    return 0;
}