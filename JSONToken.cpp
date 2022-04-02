//
// Created by Erics on 3/11/2022.
//

#include "JSONToken.hpp"
#include <iostream>

void JSONToken::print() {
    std::cout.precision(13);
    if(isNumber()) {
        std::cout << getNumber() << '\n';
    }
    else if(isWord()) {
        std::cout << getWord() << '\n';
    }
    else if(isPunct()) {
        std::cout << getPunct() << '\n';
    }
    else if (endOfFile()) {
        std::cout << ' ';
    }
    else {
        std::cout << "Uninitialized JSONToken\n";
    }
}