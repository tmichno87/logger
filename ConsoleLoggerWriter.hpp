#pragma once
#ifndef CONSOLELOGWRITER_HPP
#define CONSOLELOGWRITER_HPP

#include "LoggerWriter.hpp"
#include <memory>
#include <string>
#include <mutex>
#include <thread>

namespace SimpleLogger{


    class ConsoleLoggerWriter : public LoggerWriter{
        public:
            ConsoleLoggerWriter() = default;
            virtual ~ConsoleLoggerWriter() = default;
            virtual void write(LogLevel level, std::string message);

        private:
            std::mutex logMutex;
    };

}
#endif