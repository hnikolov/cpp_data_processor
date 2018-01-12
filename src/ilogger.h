#ifndef ILOGGER_H
#define ILOGGER_H

#include <iostream>

struct ILogger
{
    virtual ~ILogger() {}

    virtual void log( const std::string& msg, const std::string& anId ) = 0;
    virtual void enable( const bool enable )                            = 0;
};

#endif // ILOGGER_H
