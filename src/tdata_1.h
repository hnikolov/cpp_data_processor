#ifndef TDATA_1_H
#define TDATA_1_H

#include "idata.h"
#include "ilogger.h"


struct TConfig_1
{
    double d_1;
    int    i_2;
};

struct TMeasured_1
{
    double d_3;
    int    i_4;
};

struct TResults_1
{
    double d_5;
    int    i_6;
};

// --------------------------------------
class TData_1 : public IData
{
public:
    TData_1( std::string anId, ILogger &aLogger );
    virtual ~TData_1();

    // NOTE: For testing only
    friend class Test_TData_1;

    void defaultInit();

    // Interface IData
    virtual void   set_1( const double aValue ); // Configure
    virtual double get_1()                     ;
    virtual void   set_2( const int    aValue );
    virtual int    get_2()                     ;
    virtual void   set_3( const double aValue ); // Runtime
    virtual double get_3()                     ;
    virtual void   set_4( const int    aValue );
    virtual int    get_4()                     ;
    virtual void   set_5( const double aValue ); // Results
    virtual double get_5()                     ;
    virtual void   set_6( const int    aValue );
    virtual int    get_6()                     ;

private:
    TConfig_1     m_config;
    TMeasured_1   m_measured;
    TResults_1    m_results;

    std::string   m_id;
    ILogger     & m_logger;
};

#endif // TDATA_1_H
