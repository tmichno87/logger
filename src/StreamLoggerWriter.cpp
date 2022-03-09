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

    void StreamLoggerWriter::write(LogLevel level, std::string message){
        std::thread::id this_id = std::this_thread::get_id();
        std::scoped_lock lock(pImpl->logMutex);
        const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
        for(std::ostream& out : pImpl->outputs){
            out<<std::put_time(std::localtime(&t_c), "%F %T: ")<<"#"<<this_id<<" ["<<LogLevel_str[level]<<"] "<<message<<std::endl;
        }
    }

} // namespace SimpleLogger
