//
// Created by Michael Urban on 30/12/2017.
//

#include <string>
#include <sstream>
#include "MyStack.h"

#ifndef FRACTION_ONPCALCULATOR_H
#define FRACTION_ONPCALCULATOR_H

template<class T>
std::string onpCalculator(std::string input) {
    MyStack<T> stack;
    T left;
    T right;
    T converted;

    std::string token; // token, separate by spacebar
    std::stringstream ss; // stream for tokenizering
    std::istringstream toConvert; // stream for converting text to number

    int code; // code of sign for if statement

    ss.str(input); // setting string in stream

    while (std::getline(ss, token, ' ')) { // tokenizering
        code = (int) token[0]; // code of first sign of token
        if (code == 42 || code == 43 || code == 45 || code == 47) {
            // user's input is an operator
            if (stack.getSize() >= 2) {
                right = stack.pop();
                left = stack.pop();
                switch (code) {
                    case 43: // add
                        stack.push(left + right);
                        break;
                    case 45: // sub
                        stack.push(left - right);
                        break;
                    case 42: // mult
                        stack.push(left * right);
                        break;
                    case 47: // div
                        stack.push(left / right);
                        break;
                }
            } else {
                throw std::invalid_argument("You entered incorrect fraze");
            }

        } else if (code == 48) {
            throw std::invalid_argument("You cannot enter zero");
        } else if (code > 48 && code <= 57) {
            // user's input is left digit
            toConvert.str(token);
            toConvert >> converted;
            stack.push(converted);
            toConvert.clear();

        } else {
            // user entered wrong data
            throw std::invalid_argument("We cannot recognize " + token);
        }
    }


    std::stringstream toReturn;

    toReturn << "The resulf of " << input << " is " << stack.pop();
    return toReturn.str();
}

#endif //FRACTION_ONPCALCULATOR_H
