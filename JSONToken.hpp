//
// Created by Erics on 3/11/2022.
//

#ifndef PROJECT3_JSONTOKEN_HPP
#define PROJECT3_JSONTOKEN_HPP
#include <string>

class JSONToken {
// token can be {} [] , "word" 123 :
public:
    //Basic Constructor

    JSONToken(): _isNumber{false}, _isWord{false}, _isPunct{false}, _eof{false}, _punct{'\0'} {}

    //Pass ints

    JSONToken(double num): _isNumber{true}, _isWord{false}, _isPunct{false}, _eof{false}, _punct{'\0'}, _number{num}{}

    //Pass punctuation

    JSONToken(char punct): _isNumber{false}, _isWord{false}, _eof{false}, _isPunct{true}, _punct{punct} {}

    JSONToken(std::string word): _isNumber{false}, _isWord{true}, _eof{false}, _isPunct{false}, _punct{'\0'}, _word{word} {}

    bool isNumber() { return _isNumber; }
    void makeNumber(double v) {
        _number = v;
        _isNumber = true;
    }
    double getNumber() { return _number; }

    bool isWord() { return _isWord; }
    void makeWord(std::string word) {
        _word = word;
        _isWord = true;
    }
    std::string getWord() { return _word; }

    bool isPunct() { return _isPunct; }
    void makePunct(char a) {
        _punct = a;
        _isPunct = true;
    }
    char getPunct() { return _punct; }

    bool isLeftBrace() { return _punct == '{';}
    bool isRightBrace() { return _punct == '}';}
    bool isLeftBracket() { return _punct == '[';}
    bool isRightBracket() { return _punct == ']';}
    bool isComma() { return _punct == ',';}
    bool isColon() { return _punct == ':';}

    void makeEOF() { _eof = true; }
    bool endOfFile() { return _eof; }

    void print();


private:
    bool _isNumber, _isWord, _eof, _isPunct;
    double _number;
    std::string _word;
    char _punct;

};


#endif //PROJECT3_JSONTOKEN_HPP
