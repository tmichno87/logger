#include "../StreamLoggerWriter.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>


namespace SimpleLogger
{
    StreamLoggerWriter::StreamLoggerWriter(std::ostream & out){
        outputs.emplace_back(out);
    }

    void StreamLoggerWriter::addStream(std::ostream & out){
        outputs.emplace_back(out);
    }

    void StreamLoggerWriter::write(LogLevel level, std::string message){
        std::thread::id this_id = std::this_thread::get_id();
        std::scoped_lock lock(logMutex);
        const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
        for(std::ostream& out : outputs){
            out<<std::put_time(std::localtime(&t_c), "%F %T: ")<<"#"<<this_id<<" ["<<LogLevel_str[level]<<"] "<<message<<std::endl;
        }
    }

} // namespace SimpleLogger
