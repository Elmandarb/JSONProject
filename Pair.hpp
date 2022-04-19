//
// Created by Erics on 4/2/2022.
//

#ifndef PROJECT3_PAIR_HPP
#define PROJECT3_PAIR_HPP


#include <string>

class Pair { // represents a single attribute and its value:

public:
    // use the first constructor if the value of the pair is a string
    // and use the second one if it is a double value.
    // Note that this class limits the data types of values to string and double.
    Pair(std::string attributeName, std::string attributeValue);
    Pair(std::string attributeName, double num);
    bool isDouble();      // is the datatype of the value of this attribute a double?
    double numberValue();
    std::string stringValue();
    std::string attributeName();
    void printInJSON(int numSpaces);
    void printInCSV();

private:
    std::string _attributeName, _attributeStringValue;
    double _attributeNumberValue;
    bool _isNumber;
};


#endif //PROJECT3_PAIR_HPP
