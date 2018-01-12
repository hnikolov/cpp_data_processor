#include "tlogger_1.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <chrono>

TLogger_1::TLogger_1() :
    m_isEnabled( true )
{
}

TLogger_1::~TLogger_1()
{
    log( "Called destructor", "Logger_1" );
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss (aFormat = "%Y-%m-%d.%X")
const std::string TLogger_1::currentDateTime(const std::string aFormat)
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), aFormat.c_str(), &tstruct);

    return buf;
}

using namespace std::chrono;

const std::string TLogger_1::getMs()
{
    milliseconds ms = duration_cast< milliseconds >(
        system_clock::now().time_since_epoch()
    );

    ms %= 1000; // mod to get only the milliseconds

    return std::to_string( ms.count() );
}

// -----------------
// Interface ILogger
// -----------------
void TLogger_1::log( const std::string& msg, const std::string& anId )
{
    if( m_isEnabled )
    {
        std::cout << currentDateTime("%X") << '.' << getMs() << " [" << anId << "] " << msg << std::endl;
    }
}

void TLogger_1::enable( const bool enable )
{
    m_isEnabled = enable;
}
// -----------------
