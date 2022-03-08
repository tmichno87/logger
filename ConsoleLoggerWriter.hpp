#pragma once
#ifndef CONSOLELOGWRITER_HPP
#define CONSOLELOGWRITER_HPP

#include "StreamLoggerWriter.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <mutex>
#include <thread>

namespace SimpleLogger{


    class ConsoleLoggerWriter : public StreamLoggerWriter{
        public:
            ConsoleLoggerWriter() : StreamLoggerWriter(std::cout) {};
            virtual ~ConsoleLoggerWriter() = default;
    };

}
#endif