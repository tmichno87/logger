#pragma once
#ifndef SIMPLELOGGER_HPP
#define SIMPLELOGGER_HPP

#include "LogLevels.hpp"
#include "LoggerWriter.hpp"
#include <memory>
#include <functional>


namespace SimpleLogger{

        /**
         * Main class of Simple Logger
         */
        class SimpleLogger{
            public:
                /**
                 * Constructor
                 * @param minimumLevel sets minium log level
                 * @param logWriter shared pointer to LoggerWriter object, which is used to write logs to e.g. file, console, stream
                 */
                SimpleLogger(LogLevel minimumLevel, std::unique_ptr<LoggerWriter> logWriter);
                /**
                 * @brief a method for adding stream to the stream vector which is used to write logs
                 * 
                 * @param out 
                 */
                void addLogWriter(std::unique_ptr<LoggerWriter> logWriter);
                /// Default destructor
                virtual ~SimpleLogger();
                /**
                 * method for writing logs (thread safe)
                 * @param level log level
                 * @param message message to write (e.g. debug or an error information)
                 */
                void writeLog(LogLevel level, std::string message);
                /**
                 * custom method for writing logs which uses std::function<br>
                 * CAUTION! you have to provide also your own thread safe implementation in the function
                 * @param level log level
                 * @param message message to write (e.g. debug or an error information)
                 * @param func std::function which is used to write logs - it should have SimpleLogger::LogLevel and a std::string parameters
                 */
                void writeLog(LogLevel level, std::string message, std::function<void(LogLevel, std::string)> func);
            private:
                SimpleLogger() = delete;
                SimpleLogger(const SimpleLogger&) = delete;
                SimpleLogger& operator=(const SimpleLogger&) = delete;
                /// struct which hides implementation
                struct impl;
                /// pointer to implementation
                std::unique_ptr<impl> pimpl;
        };
}
#endif