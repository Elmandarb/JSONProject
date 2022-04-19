//
// Created by Erics on 4/2/2022.
//

#ifndef PROJECT3_ENTITYSET_HPP
#define PROJECT3_ENTITYSET_HPP
#include "EntityInstance.hpp"

class EntitySet {
public:
    EntitySet();

    void addEntity(EntityInstance & inst);
    void addNewPair(Pair pair, int index);
    void print();    // prints all instances of this Entity.
    std::vector<EntityInstance> getEntityInstances(); // returns "instances"
    // more member functions here.
    void printLnJSON(int numSpaces);
    void printInCSV(std::vector<std::string> keyValues);
private:
    std::vector<EntityInstance> instances;
};


#endif //PROJECT3_ENTITYSET_HPP
