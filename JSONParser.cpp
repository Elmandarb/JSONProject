//
// Created by Erics on 4/2/2022.
//

#include <iostream>
#include "JSONParser.hpp"
JSONParser::JSONParser(std::string nameOfInputFile) : tokenizer(nameOfInputFile) {

}
Pair JSONParser::parseAPair() {
    JSONToken token = tokenizer.getToken();
    if(!token.isWord()) {
        std::cout << "Error: JSONParser::parseAPair: Expected a word, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    std::string attribute = token.getWord();
    token = tokenizer.getToken();
    if(!token.isColon()) {
        std::cout << "Error: JSONParser::parseAPair: Expected a colon, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    token = tokenizer.getToken();
    if(token.isWord()) {
        Pair pair(attribute, token.getWord());
        return pair;
    }
    else if(token.isNumber()) {
        Pair doublePair(attribute, token.getNumber());
        return doublePair;
    }
    else {
        std::cout << "Error: JSONParser::parseJSONObject: Expected a word or number, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
}
EntitySet JSONParser::parseJSONEntity() {
    JSONToken token = tokenizer.getToken();
    if(!token.isLeftBracket()) {
        std::cout << "Error: JSONParser::parseJSONEntity: Expected a left bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntitySet set;
    int i = 0;
    do {
        EntityInstance instance = parseJSONObject();
        Pair id = Pair("id", i);
        instance.addPair(id);
        set.addEntity(instance);
        token = tokenizer.getToken();
        i++;
    } while (token.isComma());
    if(!token.isRightBracket()) {
        std::cout << "Error: JSONParser::parseJSONEntity: Expected an right bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return set;
}

EntityInstance JSONParser::parseJSONObject() {
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
    JSONToken token = tokenizer.getToken();
    if( ! token.isLeftBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        instance.addPair(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, the above loop terminates when we did not find a comma.
    // that means we have parsed an entire object. In that case, token must contain
    // the close brace of that object.
    if( ! token.isRightBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}