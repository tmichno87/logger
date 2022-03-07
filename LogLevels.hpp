#pragma once
#ifndef LOGLEVELS_HPP
#define LOGLEVELS_HPP

namespace SimpleLogger{
        enum LogLevel {ERROR, DEBUG, INFO, WARNING};
        static const char *LogLevel_str[] = { "ERROR", "DEBUG", "INFO", "WARNING" };
}
#endif