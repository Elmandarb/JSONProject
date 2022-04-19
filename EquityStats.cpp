//
// Created by Erics on 4/12/2022.
//

#include <iostream>
#include "EquityStats.hpp"
EquityStats::EquityStats(EntitySet set) {
    _set = set;
}

void EquityStats::calculateExponentialMovingAverage(int days) {
    double term = (2.0)/(1.0+days);     // Calculate Term for s/(1+d)
    double average = 0.0;
    int i = 0;
    std::vector<EntityInstance> instances = _set.getEntityInstances();
    while(i<days) {                     // Calculate the average of first x days to use as base EMA
        average += instances.at(i).close();
        i++;
    }
    average = average/days;
    double EMA = average; //Calculate the first EMA and store it
    std::string name;
    if(days == 12) {
        name = "EMA-12";
    }
    else {
        name = "EMA-26";
    }
    Pair pair(name, EMA);
    i--;
    instances.at(i).addPair(pair);
    _set.addNewPair(pair,i);
    i++;
    while(i<instances.size()) {
        if(days == 12) {
            average = instances.at(i - 1).EMA12();
        }
        if(days == 26) {
            average = instances.at(i - 1).EMA26();
        }
        EMA = (instances.at(i).close() * term) + (average * (1-term));
        /*
        std::cout << '\n' << average << '\n';
        std::cout << "instances.at(i).close() = " << instances.at(i).close();
        std::cout << "  term = " << term;
        std::cout << "  average 8 (1-term) = " << (average * (1-term)) << "\n";
         */
        Pair loopPair(name,EMA);
        instances.at(i).addPair(loopPair);
        _set.addNewPair(loopPair,i);
        i++;
    }
}

void EquityStats::calculateMACD() {
    std::vector<EntityInstance> instances = _set.getEntityInstances();
    int days = 25;
    double twentySix;
    double twelve;
    double MACD;
    while(days < instances.size()) {
        twentySix = instances.at(days).EMA26();
        twelve = instances.at(days).EMA12();
        MACD = twelve - twentySix;
        Pair pair("MACD",MACD);
        _set.addNewPair(pair,days);
        days++;
    }
}
//
void EquityStats::calculateSignal(int days) {
    // go to 26 get average of first days then EMA-days the whole thing
    //adding pairs for all signals
    double term = 2.0/(1.0+days);
    double average = 0.0;
    int i = 25;
    std::vector<EntityInstance> instances = _set.getEntityInstances();
    while(i<days+25) {
        std::cout << "instances.at(i).MACD()  = " << instances.at(i).MACD() << '\n';
        average += instances.at(i).MACD();
        i++;
    }
    average = average/days;
    std::cout << "average = " << average << '\n';
    double signal = average;
    std::string name = "Signal";
    Pair pair(name, signal);
    i--;
    _set.addNewPair(pair,i);
    instances.at(i).addPair(pair);
    i++;

    while(i<instances.size()) {
        signal = (instances.at(i).MACD() * term) + (signal * (1-term));
        Pair loopPair(name,signal);
        instances.at(i).addPair(loopPair);
        _set.addNewPair(loopPair,i);
        i++;
    }
}
//
void EquityStats::print(std::vector<std::string> attributes) {
//Prints the attributes as a csv using the internal Entity set _set
    _set.printInCSV(attributes);
}

void EquityStats::printInJSON(int numSpaces) {
    _set.printLnJSON(numSpaces);
}