#ifndef TDATA_1_H
#define TDATA_1_H

#include "tintfdata.h"
#include "tintflogger.h"


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
class TData_1 : public TIntfData
{
public:
    TData_1( std::string anId, TIntfLogger &aLogger );
    virtual ~TData_1();

    // NOTE: For testing only
    friend class Test_TData_1;

    void defaultInit();

    // Interface TIntfData
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
    TIntfLogger & m_logger;
};

// ============================================

class Test_TData_1
{
public:
    Test_TData_1( std::string anId, TIntfLogger &aLogger );

    void run();

private:
    TData_1 DUT;

    void assert_double(double aD1, double aD2 );
    void assert_int( int val_1, int val_2 ); // We can use assert_double instead

    // Tests
    void test_defaultInit();
    void test_set_1(); // Configure
    void test_get_1();
    void test_set_2();
    void test_get_2();
    void test_set_3(); // Runtime
    void test_get_3();
    void test_set_4();
    void test_get_4();
    void test_set_5(); // Results
    void test_get_5();
    void test_set_6();
    void test_get_6();

    std::string   m_id;
    TIntfLogger & m_logger;
};

#endif // TDATA_1_H
