#include <iostream>
#include "JSONTokenizer.hpp"
int main(int argc, char *argv[]) {
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if( ! inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }
    inputStream.close();

    JSONTokenizer jsonTokenizer(argv[1]); // The Tokenizer opens and reads from the input file.
    JSONToken token = jsonTokenizer.getToken();
    while( ! token.endOfFile() ) {
        token.print();
        token = jsonTokenizer.getToken();
    }
    return 0;
}
