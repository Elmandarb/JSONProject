//
// Created by Erics on 4/12/2022.
//

#ifndef PROJECT3_EQUITYSTATS_HPP
#define PROJECT3_EQUITYSTATS_HPP
#include "EntitySet.hpp"

class EquityStats {
public:
    EquityStats(EntitySet set);
    void print(std::vector<std::string> attributes);
    void printInJSON(int numSpaces);
    //Helpers for formulas
    void calculateExponentialMovingAverage(int days);
    void calculateMACD();
    void calculateSignal(int days);
private:
    EntitySet _set;
};


#endif //PROJECT3_EQUITYSTATS_HPP
