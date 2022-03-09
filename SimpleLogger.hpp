#pragma once
#ifndef SIMPLELOGGER_HPP
#define SIMPLELOGGER_HPP

#include "LogLevels.hpp"
#include "LoggerWriter.hpp"
#include <memory>
#include <functional>


namespace SimpleLogger{
        class SimpleLogger{
            public:
                SimpleLogger(std::shared_ptr<LoggerWriter> logWriter, LogLevel minimumLevel = DEBUG) : writer(std::move(logWriter)), logLevel(minimumLevel){};
                virtual ~SimpleLogger() = default;
                void writeLog(LogLevel level, std::string message);
                void writeLog(LogLevel level, std::string message, std::function<void(LogLevel, std::string)> func);
            private:
                SimpleLogger() = delete;
                std::shared_ptr<LoggerWriter> writer;
                LogLevel logLevel;
        };
}
#endif