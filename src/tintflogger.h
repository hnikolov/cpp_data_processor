#ifndef TINTFLOGGER_H
#define TINTFLOGGER_H

#include <iostream>

struct TIntfLogger
{
    virtual void log( const std::string& msg, const std::string& anId ) = 0;
    virtual void enable( const bool enable )                            = 0;
};

#endif // TINTFLOGGER_H
