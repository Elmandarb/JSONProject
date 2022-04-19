#include <iostream>
#include "JSONTokenizer.hpp"
#include "JSONParser.hpp"
#include "EntitySet.hpp"
#include "EntityInstance.hpp"
#include "Pair.hpp"
#include "EquityStats.hpp"
int main(int argc, char *argv[]) {
    std::ifstream inputStream;
    if(argc != 3) {
        std::cout << "wrong number of args\n";
    }
    inputStream.open(argv[2], std::ios::in);    // open for reading
    if( ! inputStream.is_open()) {
        std::cout << "Unable top open " << argv[2] << ". Terminating...";
        exit(2);
    }
    inputStream.close();
    JSONParser parser(argv[2]);
    EntitySet set = parser.parseJSONEntity();
    EquityStats stats = EquityStats(set);
    stats.calculateExponentialMovingAverage(12);
    stats.calculateExponentialMovingAverage(26);
    stats.calculateMACD();
    stats.calculateSignal(9);
    std::vector<std::string> attributesToPrint = {"Date" ,"Open", "High", "Low",  "Close", "Volume", "EMA-12", "EMA-26", "MACD", "Signal"};
    std::string tag = argv[1];
    if("-json" == tag) {
        stats.printInJSON(5);
    }
    else if(tag == "-csv") {
        stats.print(attributesToPrint);
    }
    else {
        std::cout << "Wrong Tag choose either -json or -csv\n";
    }
    /*JSONTokenizer jsonTokenizer(argv[1]); // The Tokenizer opens and reads from the input file.
    JSONToken token = jsonTokenizer.getToken();
    while( ! token.endOfFile() ) {
        token.print();
        token = jsonTokenizer.getToken();
    }*/
    return 0;
}
