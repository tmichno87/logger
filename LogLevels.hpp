#pragma once
#ifndef LOGLEVELS_HPP
#define LOGLEVELS_HPP

namespace SimpleLogger{
        enum LogLevel {DEBUG, INFO, WARNING, ERROR, NONE};
        static const char *LogLevel_str[] = { "DEBUG", "INFO", "WARNING", "ERROR", "NONE" };
}
#endif