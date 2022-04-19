//
// Created by Erics on 4/2/2022.
//

#include <iostream>
#include "Pair.hpp"
#include<iomanip>
#include <cmath>

Pair::Pair(std::string attributeName, std::string attributeValue) {
    _attributeName = attributeName;
    _attributeStringValue = attributeValue;
    _isNumber = false;
}
Pair::Pair(std::string attributeName, double num) {
    _attributeName = attributeName;
    _attributeNumberValue = num;
    _isNumber = true;
}
bool Pair::isDouble() {
    return _isNumber;
}
double Pair::numberValue() {
    return _attributeNumberValue;
}
std::string Pair::attributeName() {
    return _attributeName;
}
std::string Pair::stringValue() {
    return _attributeStringValue;
}
void Pair::printInJSON(int numSpaces) {
    std::string spaces;
    for(int i = 0; i<numSpaces; i++) {
        spaces.push_back(' ');
    }
    std::cout << spaces << "\"" << this->_attributeName << "\": ";
    if(this->isDouble()) {
        if(this->attributeName() == "Volume") {
            std::cout << std::fixed << std::setprecision(0) << this->numberValue();
        }
        else if(this->attributeName() == "id") {
            std::cout << std::fixed << std::setprecision(0) << this->numberValue();
        }
        else if(this->attributeName() == "StockSplits") {
            std::cout << std::fixed << std::setprecision(0) << this->numberValue();
        }
        else if(this->attributeName() == "Dividends") {
            std::cout << std::fixed << std::setprecision(0) << this->numberValue();
        }
        else {
            std::cout << std::fixed << std::setprecision(4) << this->numberValue();
        }
    }
    else {
        std::cout << "\"" << this->stringValue() << "\"";
    }
}
void Pair::printInCSV() {
    if(isDouble()) {
        if(this->attributeName() == "Volume") {
            std::cout << std::fixed << std::setprecision(0) << this->numberValue();
        }
        else if(this->attributeName() == "id") {
            std::cout << std::fixed << std::setprecision(0) << this->numberValue();
        }
        else if(this->attributeName() == "StockSplits") {
            std::cout << std::fixed << std::setprecision(0) << this->numberValue();
        }
        else if(this->attributeName() == "Dividends") {
            std::cout << std::fixed << std::setprecision(0) << this->numberValue();
        }
        else {
            std::cout << std::fixed << std::setprecision(4) << this->numberValue();
        }
    }
    else {
        std::cout << std::fixed << std::setprecision(4) << stringValue();
    }
}