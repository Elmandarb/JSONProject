//
// Created by Erics on 4/2/2022.
//

#ifndef PROJECT3_ENTITYINSTANCE_HPP
#define PROJECT3_ENTITYINSTANCE_HPP
#include "Pair.hpp"
#include <vector>

class EntityInstance {
public:
    void addPair(Pair &pair); // Add a new pair to this entity.
    int numAttributes();  // how many pairs are in this instance?
    std::vector<std::string> attributeNames();
    void print();   // prints this object.
    // more member functions here when necessary.

    double close();   // an accessor function that return the
    // value associated with an attribute. In this case, the value.
    // of attribute, Close. You will need to add more such functions
    // to this class.
    double open();
    double high();
    double low();
    double volume();
    double dividends();
    double stockSplits();
    std::string date();
    double timestamp();
    double EMA12();
    double EMA26();
    double MACD();
    double signal();
    void printInJSON(int numSpaces);
    void printInCSV(std::vector<std::string> keyValues);
private:
    std::vector<Pair> entityPairs;
    // more variables here as necessary.
};


#endif //PROJECT3_ENTITYINSTANCE_HPP
