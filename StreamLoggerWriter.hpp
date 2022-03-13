#pragma once
#ifndef STREAMLOGWRITER_HPP
#define STREAMLOGWRITER_HPP

#include "LoggerWriter.hpp"
#include <memory>
#include <ostream>

namespace SimpleLogger{

    /// Class which is used for logging to streams (implements PIMPL)
    class StreamLoggerWriter : public LoggerWriter{
        public:
            /**
             * @brief Construct a new Stream Logger Writer object
             * 
             * @param out a stream to which the logs should be written
             */
            StreamLoggerWriter(std::ostream & out);
            /**
             * @brief Destroy the Stream Logger Writer object
             * 
             */
            virtual ~StreamLoggerWriter();
            /**
             * @brief a method for adding stream to the stream vector which is used to write logs
             * 
             * @param out 
             */
            void addStream(std::ostream & out);
            /**
             * @brief write method, which writes logs to a vector of streams
             * 
             * @param message message to write
             */
            virtual void write(std::string message) override;
        private:
            /// struct which hides implementation
            struct impl;
            /// pointer to implementation
            std::unique_ptr<impl> pImpl;      
    };

}
#endif