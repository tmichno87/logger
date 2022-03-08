#include "../SimpleLogger.hpp"
#include <iostream>
#include <memory>

namespace SimpleLogger{

    void SimpleLogger::writeLog(LogLevel level, std::string message){
        if(level >= logLevel)
            writer->write(level, message);
    }
}
