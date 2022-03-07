#include "../SimpleLogger.hpp"
#include <iostream>
#include <memory>

namespace SimpleLogger{

    void SimpleLogger::writeLog(LogLevel level, std::string message){
        writer->write(level, message);
    }
}
