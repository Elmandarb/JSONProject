//
// Created by Erics on 3/11/2022.
//
#ifndef PROJECT3_JSONTOKENIZER_HPP
#define PROJECT3_JSONTOKENIZER_HPP

#include <fstream>
#include <string>
#include "JSONToken.hpp"

class JSONTokenizer {
public:
    JSONTokenizer(std::string fileName);
    JSONToken getToken();
private:
    std::fstream inputStream;
    std::string inputFileName;
    bool isPunct(char c);
    bool isWord(char c);
};


#endif //PROJECT3_JSONTOKENIZER_HPP
