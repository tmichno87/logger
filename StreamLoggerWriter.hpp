#pragma once
#ifndef STREAMLOGWRITER_HPP
#define STREAMLOGWRITER_HPP

#include "LoggerWriter.hpp"
#include <memory>
#include <ostream>

namespace SimpleLogger{

    class StreamLoggerWriter : public LoggerWriter{
        public:
            StreamLoggerWriter(std::ostream & out);
            virtual ~StreamLoggerWriter();
            void addStream(std::ostream & out);
            virtual void write(LogLevel level, std::string message) override;
        private:
            struct impl;
            std::unique_ptr<impl> pImpl;      
    };

}
#endif