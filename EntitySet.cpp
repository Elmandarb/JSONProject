//
// Created by Erics on 4/2/2022.
//

#include <iostream>
#include "EntitySet.hpp"
void EntitySet::addEntity(EntityInstance & inst) {
    instances.push_back(inst);
}
EntitySet::EntitySet() {
    std::vector<EntityInstance> instance;
    instances = instance;
}
void EntitySet::printLnJSON(int numSpaces) {
    std::cout << "[\n";
    int i = 0;
    while(i < instances.size()) {
        instances.at(i).printInJSON(numSpaces);
        if(i < instances.size() - 1) {
            std::cout << ",\n";
        }
        else {
            std::cout << "\n]\n";
        }
        i++;
    }
}
void EntitySet::print() {
    int i = 0;
    while(i < instances.size()) {
        instances.at(i).print();
        i++;
    }
}
std::vector<EntityInstance> EntitySet::getEntityInstances() {
    return instances;
}
void EntitySet::printInCSV(std::vector<std::string> keyValues) {
    int i = 0;
    while(i < keyValues.size()) {
        if(i > 0) {
            std::cout << ',';
        }
        std::cout << keyValues.at(i);
        i++;
    }
    std::cout << '\n';
    i = 0;
    while(i < instances.size()) {
        instances.at(i).printInCSV(keyValues);
        i++;
        std::cout << '\n';
    }
}
void EntitySet::addNewPair(Pair pair, int index) {
    if(index < instances.size()) {
        instances.at(index).addPair(pair);
    }
}