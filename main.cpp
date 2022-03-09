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
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter);

    logger->writeLog(SimpleLogger::INFO, "test info");
    logger->writeLog(SimpleLogger::DEBUG, "test debug");
    logger->writeLog(SimpleLogger::ERROR, "test error");

    

    auto testLambdaLog = [&logger](){
        std::cout<< "testLambdaLog executed" << std::endl;
        logger->writeLog(SimpleLogger::DEBUG, "test debug from testLambdaLog before sleep");
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::cout<< "testLambdaLog executed" << std::endl;
        logger->writeLog(SimpleLogger::DEBUG, "test debug from testLambdaLog after sleep");
    };

    auto logWriteLambda = [](SimpleLogger::LogLevel level, std::string message){
        std::cout << "Custom log writer lambda test " << SimpleLogger::LogLevel_str[level] << ", " << message <<std::endl;
    };

    logger->writeLog(SimpleLogger::DEBUG, "test custom log write", logWriteLambda);

    testLambdaLog();

}
