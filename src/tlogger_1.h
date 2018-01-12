#ifndef TLOGGER_1_H
#define TLOGGER_1_H

#include"ilogger.h"
#include <iostream>

class TLogger_1 : public ILogger
{
public:
    TLogger_1();
    virtual ~TLogger_1();

    // Interface TIntfLogger
    virtual void log( const std::string& msg, const std::string& anId );
    void enable( const bool enable );

private:
    const std::string currentDateTime( const std::string aFormat );
    const std::string getMs();
    bool m_isEnabled;
};

#endif // TLOGGER_1_H
