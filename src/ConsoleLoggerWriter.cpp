#include "../ConsoleLoggerWriter.hpp"
#include <iostream>


namespace SimpleLogger
{
    void ConsoleLoggerWriter::write(LogLevel level, std::string message){
        std::thread::id this_id = std::this_thread::get_id();
        std::scoped_lock lock(logMutex);
        std::cout<<"#"<<this_id<<" ["<<LogLevel_str[level]<<"] "<<message<<std::endl;
    }

} // namespace SimpleLogger
