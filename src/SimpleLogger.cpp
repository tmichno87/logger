#include "../SimpleLogger.hpp"
#include <iostream>
#include <memory>

namespace SimpleLogger{

    void SimpleLogger::writeLog(LogLevel level, std::string message){
        if(level >= logLevel)
            writer->write(level, message);
    }

    void SimpleLogger::writeLog(LogLevel level, std::string message, std::function<void(LogLevel, std::string)> func){
        if(level >= logLevel)
            func(level, message);
    }
}
