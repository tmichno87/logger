#include "SimpleLogger.hpp"
#include "ConsoleLoggerWriter.hpp"
#include "StreamLoggerWriter.hpp"
#include <iostream>
#include <fstream>

int main(int, char**) {
    std::cout << "Simple logger example!\n";

    // open file for logs (in this case overwriting is chosen):
    std::ofstream myfile;
    myfile.open ("logs.txt");
    // create stream writer on a basis of the file
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(myfile);
    // add output to console
    streamWriter->addStream(std::cout);
    // create logger object
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter);

    // test different types of log levels
    logger->writeLog(SimpleLogger::INFO, "test info");
    logger->writeLog(SimpleLogger::DEBUG, "test debug");
    logger->writeLog(SimpleLogger::ERROR, "test error");

    // test using logs in lambdas
    auto testLambdaLog = [&logger](){
        std::cout<< "testLambdaLog executed" << std::endl;
        logger->writeLog(SimpleLogger::DEBUG, "test debug from testLambdaLog before sleep");
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::cout<< "testLambdaLog executed" << std::endl;
        logger->writeLog(SimpleLogger::DEBUG, "test debug from testLambdaLog after sleep");
    };

    testLambdaLog();

    // test using own std::function to write logs
    auto logWriteLambda = [](SimpleLogger::LogLevel level, std::string message){
        std::cout << "Custom log writer lambda test " << SimpleLogger::LogLevel_str[level] << ", " << message <<std::endl;
    };

    logger->writeLog(SimpleLogger::DEBUG, "test custom log write", logWriteLambda);

    

}
