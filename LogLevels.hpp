#pragma once
#ifndef LOGLEVELS_HPP
#define LOGLEVELS_HPP

namespace SimpleLogger{
        /// log levels enums (do not modify their order)
        enum LogLevel {DEBUG, INFO, WARNING, ERROR, NONE};
        /// log levels enums translated to string represtation (do not modify their order)
        static const char *LogLevel_str[] = { "DEBUG", "INFO", "WARNING", "ERROR", "NONE" };
}
#endif