#ifndef IDATA_H
#define IDATA_H

struct IData
{
    virtual ~IData() {}

    virtual void   set_1( const double aValue ) = 0; // Configure
    virtual double get_1()                      = 0;
    virtual void   set_2( const int    aValue ) = 0;
    virtual int    get_2()                      = 0;
    virtual void   set_3( const double aValue ) = 0; // Runtime
    virtual double get_3()                      = 0;
    virtual void   set_4( const int    aValue ) = 0;
    virtual int    get_4()                      = 0;
    virtual void   set_5( const double aValue ) = 0; // Results
    virtual double get_5()                      = 0;
    virtual void   set_6( const int    aValue ) = 0;
    virtual int    get_6()                      = 0;
};

#endif // IDATA_H
