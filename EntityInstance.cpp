//
// Created by Erics on 4/2/2022.
//

#include <iostream>
#include "EntityInstance.hpp"
void EntityInstance::addPair(Pair &pair) {
    entityPairs.push_back(pair);
}
int EntityInstance::numAttributes() {
    return entityPairs.size();
}
std::vector<std::string> EntityInstance::attributeNames() {
    std::vector<std::string> list;
    int i = 0;
    while(i<entityPairs.size()) {
        list.push_back(entityPairs.at(i).attributeName());
    }
    return list;
}
void EntityInstance::printInJSON(int numSpaces) {
    std::string spaces;
    for(int i = 0; i<numSpaces; i++) {
        spaces.push_back(' ');
    }
    std::cout << spaces << "{\n";
    int j = 0;
    while(j < entityPairs.size()) {
        std::cout << spaces;
        entityPairs.at(j).printInJSON(numSpaces);
        if(j < entityPairs.size() - 1) {
            std::cout << ",\n";
        }
        else {
            std::cout << "\n" << spaces << "}";
        }
        j++;
    }
}
void EntityInstance::print() {
    if(entityPairs.empty()) {
        return;
    }
    int i = 0;
    while(i<entityPairs.size()) {
        Pair instance = entityPairs.at(i);
        if(instance.isDouble()) {
            std::cout << instance.attributeName() << " : " << instance.numberValue() << "\n";
        }
        else {
            std::cout << instance.attributeName() << " : " << instance.stringValue() << "\n";
        }
        i++;
    }
}
double EntityInstance::close() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "Close") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::open() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "Open") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
std::string EntityInstance::date() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "Date") {
            return entityPairs.at(i).stringValue();
        }
        i++;
    }
    return "2021-01-01";
}
double EntityInstance::high() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "High") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::low() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "Low") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::dividends() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "Dividends") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::stockSplits() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "Stock Splits") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::timestamp() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "Timestamp") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::volume() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "Volume") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::EMA12() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "EMA-12") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::EMA26() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "EMA-26") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::signal() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "Signal") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
double EntityInstance::MACD() {
    int i = 0;
    while (i<entityPairs.size()) {
        if(entityPairs.at(i).attributeName() == "MACD") {
            return entityPairs.at(i).numberValue();
        }
        i++;
    }
    return 0.0;
}
void EntityInstance::printInCSV(std::vector<std::string> keyValues) {
    int i = 0;
    while(i<keyValues.size()) {
        std::string placeHolder = keyValues.at(i);
        if(i > 0 && i < keyValues.size()) {
            std::cout << ',';
        }
        for(int x = 0;x<entityPairs.size();x++) {
            if(placeHolder == entityPairs.at(x).attributeName()) {
                entityPairs.at(x).printInCSV();
            }
        }
        i++;
    }
}