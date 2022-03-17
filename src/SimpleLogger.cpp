#include "../SimpleLogger.hpp"
#include <iostream>
#include <memory>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <mutex>
#include <thread>
#include <vector>
#include <functional>
#include <sstream>

namespace SimpleLogger{

    struct SimpleLogger::impl{
        impl();
        ~impl();
        std::vector<std::unique_ptr<LoggerWriter>> logWriters;
        LogLevel minLogLevel;

        void writeLog(LogLevel level, std::string message);

    };

    SimpleLogger::impl::impl(){}

    SimpleLogger::impl::~impl(){}

    void SimpleLogger::impl::writeLog(LogLevel level, std::string message){
        if(level < minLogLevel)
            return;
        std::thread::id this_id = std::this_thread::get_id();
        const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
        std::stringstream sstr;
        sstr <<std::put_time(std::localtime(&t_c), "%F %T: ")<<"#"<<this_id<<" ["<<LogLevel_str[level]<<"] "<<message<<std::endl;
        auto fullLogMessage = sstr.str();
        for (auto const& lw: logWriters){
            lw->write(fullLogMessage);
        }
    }

    SimpleLogger::SimpleLogger(LogLevel minimumLevel, std::unique_ptr<LoggerWriter> logWriter) {
        pimpl = std::move(std::make_unique<impl>());
        pimpl->minLogLevel = minimumLevel;
        pimpl->logWriters.push_back(std::move(logWriter));
    }

    void SimpleLogger::addLogWriter(std::unique_ptr<LoggerWriter> logWriter){
        pimpl->logWriters.push_back(std::move(logWriter));
    }

    void SimpleLogger::addLogWriters(std::vector<std::unique_ptr<LoggerWriter>>& vecLogWriters){
        std::move(vecLogWriters.begin(), vecLogWriters.end(), std::back_inserter(pimpl->logWriters));
    }

    SimpleLogger::~SimpleLogger(){}



    void SimpleLogger::writeLog(LogLevel level, std::string message){
        pimpl->writeLog(level, message);
    }

    void SimpleLogger::writeLog(LogLevel level, std::string message, std::function<void(LogLevel, std::string)> func){
        if(level >= pimpl->minLogLevel)
            func(level, message);
    }
}
