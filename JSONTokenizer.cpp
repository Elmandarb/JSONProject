//
// Created by Erics on 3/11/2022.
//

#include "JSONTokenizer.hpp"
#include <iostream>
#include "JSONTokenizer.hpp"

JSONTokenizer::JSONTokenizer(std::string fileName): inputFileName{fileName} {
    inputStream.open(inputFileName, std::ios::in);
}

JSONToken JSONTokenizer::getToken() {
    if(!inputStream.is_open()) {
        std::cout << "Tokenizer::getToken -- Input File " << inputFileName << " is not open\n";
        exit(3);
    }
    char c;
    inputStream >> c; // only place in JSONTokenizer you use >> operator
    // only read a char at a time no strings
    if(inputStream.eof()) {
        JSONToken token;
        token.makeEOF();
        return token;
    }
    else if(isdigit(c)) {
        inputStream.putback(c);
        double value;
        inputStream >> value;
        //std::cout << "value is " << value << '\n';
        JSONToken token(value);
        return token;
    }
    else if(isWord(c)) {
        std::string s;
        inputStream >> c;
        while(!isWord(c)) {
            s.push_back(c);
            inputStream >> c;
        }
        JSONToken token(s);
        return token;
    }
    else if(isPunct(c)) {
        JSONToken token(c);
        return token;
    }
    std::cout << "Unexpected Char -> " << c << "in input. Terminating.\n";
    exit(1);
}
bool JSONTokenizer::isPunct(char c) {
    return (c == '[' || c == '}' || c == ']' || c == '{' || c == ':'|| c == ',');
}
bool JSONTokenizer::isWord(char c) {
    return (c == '"');
}