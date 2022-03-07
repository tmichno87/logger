#include "SimpleLogger.hpp"
#include "ConsoleLoggerWriter.hpp"
#include <iostream>

int main(int, char**) {
    std::cout << "Hello, world!\n";

    auto consoleWriter = std::make_shared<SimpleLogger::ConsoleLoggerWriter>();
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(consoleWriter);

    logger->writeLog(SimpleLogger::INFO, "test");

}
