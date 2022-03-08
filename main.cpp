#include "SimpleLogger.hpp"
#include "ConsoleLoggerWriter.hpp"
#include "StreamLoggerWriter.hpp"
#include <iostream>
#include <fstream>

int main(int, char**) {
    std::cout << "Simple logger example!\n";

    std::ofstream myfile;
    myfile.open ("logs.txt");
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(myfile);
    streamWriter->addStream(std::cout);
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter, SimpleLogger::INFO);

    logger->writeLog(SimpleLogger::INFO, "test info");
    logger->writeLog(SimpleLogger::DEBUG, "test debug");
    logger->writeLog(SimpleLogger::ERROR, "test error");

}
