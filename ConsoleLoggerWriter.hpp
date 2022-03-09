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
    /// Class which writes logs to console (std::cout)
    class ConsoleLoggerWriter : public StreamLoggerWriter{
        public:
            /**
             * @brief Construct a new Console Logger Writer object
             * 
             */
            ConsoleLoggerWriter() : StreamLoggerWriter(std::cout) {};
            /**
             * @brief Destroy the Console Logger Writer object
             * 
             */
            virtual ~ConsoleLoggerWriter() = default;
    };

}
#endif