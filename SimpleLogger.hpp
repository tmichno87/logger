#pragma once
#ifndef SIMPLELOGGER_HPP
#define SIMPLELOGGER_HPP

#include "LogLevels.hpp"
#include "LoggerWriter.hpp"
#include <memory>


namespace SimpleLogger{
        class SimpleLogger{
            public:
                SimpleLogger(std::shared_ptr<LoggerWriter> logWriter) : writer(std::move(logWriter)){};
                virtual ~SimpleLogger() = default;
                void writeLog(LogLevel level, std::string message);
            private:
                SimpleLogger() = delete;
                std::shared_ptr<LoggerWriter> writer;
        };
}
#endif