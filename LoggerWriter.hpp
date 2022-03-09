#pragma once
#ifndef LOGWRITER_HPP
#define LOGWRITER_HPP

#include "LogLevels.hpp"
#include <string>

namespace SimpleLogger{
    /// Base class for logger writers which are used to write logs for example to std:cout or a file
    class LoggerWriter{
        public:
            /**
             * @brief Construct a new Logger Writer object
             * 
             */
            LoggerWriter() = default;
            /**
             * @brief virtual method for writing logs
             * 
             * @param level log level
             * @param message message
             */
            virtual void write(LogLevel level, std::string message) = 0;
            /**
             * @brief Destroy the Logger Writer object
             * 
             */
            virtual ~LoggerWriter() = default;
    };

}
#endif