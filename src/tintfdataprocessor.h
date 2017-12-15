#ifndef TINTFDATAPROCESSOR_H
#define TINTFDATAPROCESSOR_H

// ----------------------
// Client-side interface
// ----------------------
struct TIntfDataProcessor
{
    virtual void   set_1( const double aValue )    = 0;
    virtual void   set_4( const int    aValue )    = 0;
    virtual double get_5()                         = 0;

    virtual void   calculate_1()                   = 0;

    virtual void   enable_log( const bool enable ) = 0;
};

#endif // TINTFDATAPROCESSOR_H
