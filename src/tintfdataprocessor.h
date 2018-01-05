#ifndef TINTFDATAPROCESSOR_H
#define TINTFDATAPROCESSOR_H

#include <iostream>

// ----------------------
// Client-side interface
// ----------------------
struct TIntfDataProcessor
{
    virtual ~TIntfDataProcessor() {}

    virtual void        set_1( const double aValue )    = 0;
    virtual void        set_4( const int    aValue )    = 0;
    virtual double      get_5()                         = 0;

    virtual void        calculate_1()                   = 0;

    virtual void        enable_log( const bool enable ) = 0;

    virtual std::string getId()                         = 0;
};

#endif // TINTFDATAPROCESSOR_H
