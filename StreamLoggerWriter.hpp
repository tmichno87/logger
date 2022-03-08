#pragma once
#ifndef STREAMLOGWRITER_HPP
#define STREAMLOGWRITER_HPP

#include "LoggerWriter.hpp"
#include <memory>
#include <string>
#include <mutex>
#include <thread>
#include <ostream>
#include <vector>
#include <functional>

namespace SimpleLogger{


    class StreamLoggerWriter : public LoggerWriter{
        public:
            StreamLoggerWriter(std::ostream & out);
            virtual ~StreamLoggerWriter() = default;
            void addStream(std::ostream & out);
            virtual void write(LogLevel level, std::string message);
        private:
            std::mutex logMutex;
            std::vector<std::reference_wrapper<std::ostream>> outputs;
    };

}
#endif