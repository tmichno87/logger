#pragma once
#ifndef LOGWRITER_HPP
#define LOGWRITER_HPP

#include "LogLevels.hpp"
#include <string>

namespace SimpleLogger{

    class LoggerWriter{
        public:
            LoggerWriter() = default;
            virtual void write(LogLevel level, std::string message) = 0;
            virtual ~LoggerWriter() = default;
    };

}
#endif