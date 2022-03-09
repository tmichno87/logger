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
                 * @param logWriter shared pointer to LoggerWriter object, which is used to write logs to e.g. file, console, stream
                 * @param minimumLevel sets minium log level
                 */
                SimpleLogger(std::shared_ptr<LoggerWriter> logWriter, LogLevel minimumLevel = DEBUG) : writer(std::move(logWriter)), logLevel(minimumLevel){};
                /// Default destructor
                virtual ~SimpleLogger() = default;
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
                std::shared_ptr<LoggerWriter> writer;
                LogLevel logLevel;
        };
}
#endif