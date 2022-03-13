#include "../StreamLoggerWriter.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <mutex>
#include <thread>
#include <vector>
#include <functional>

namespace SimpleLogger
{
    /**
     * @brief StreamLoggerWriter implementation struct
     * 
     */
    struct StreamLoggerWriter::impl{
        impl();
        ~impl();
        std::mutex logMutex;
        std::vector<std::reference_wrapper<std::ostream>> outputs;
    };

    StreamLoggerWriter::impl::impl(){}

    StreamLoggerWriter::impl::~impl(){}

    StreamLoggerWriter::~StreamLoggerWriter(){}

    StreamLoggerWriter::StreamLoggerWriter(std::ostream & out){
        pImpl = std::make_unique<impl>();
        pImpl->outputs.emplace_back(out);
    }

    void StreamLoggerWriter::addStream(std::ostream & out){
        pImpl->outputs.emplace_back(out);
    }

    void StreamLoggerWriter::write(std::string message){
         for(std::ostream& out : pImpl->outputs){
            out<<message<<std::endl;
        }
    }

} // namespace SimpleLogger
