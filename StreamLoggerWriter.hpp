#pragma once
#ifndef STREAMLOGWRITER_HPP
#define STREAMLOGWRITER_HPP

#include "Common.hpp"
#include "LoggerWriter.hpp"
#include <memory>
#include <ostream>
#include <vector>

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
             * @brief Construct a new Stream Logger Writer object
             * 
             * @tparam Args 
             * @param out a stream to which the logs should be written
             * @param args another streams to which the logs should be written
             * @return requires 
             */
            template <class ... Args> requires AllSame<Args...>
            StreamLoggerWriter(std::ostream & out, Args& ... args) : StreamLoggerWriter(out)
            {
                std::vector<std::reference_wrapper<std::ostream>> tmpVec;
                ((tmpVec.push_back(args)), ...);
                addStreams(tmpVec);
            }
            /**
             * @brief Destroy the Stream Logger Writer object
             * 
             */
            virtual ~StreamLoggerWriter();
            /**
             * @brief a method for adding stream to the stream vector which is used to write logs
             * 
             * @param out ostream output to write logs
             */
            void addStream(std::ostream & out);
            /**
             * @brief a method for adding stream to the stream vector which is used to write logs
             * 
             * @param outs ostream output to write logs
             */
            void addStreams(std::vector<std::reference_wrapper<std::ostream>>& outs);
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