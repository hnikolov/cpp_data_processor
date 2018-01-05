#include "tdata_1.h"
#include <iostream>

TData_1::TData_1( std::string anId, TIntfLogger &aLogger ) :
    m_id    ( anId    ),
    m_logger( aLogger )
{
    defaultInit();
}

TData_1::~TData_1()
{
    m_logger.log( "Called destuctor", m_id );
}

void TData_1::defaultInit()
{
    m_config.d_1   = 0.0;
    m_config.i_2   = 0;

    m_measured.d_3 = 0.0;
    m_measured.i_4 = 0;

    m_results.d_5  = 0.0;
    m_results.i_6  = 0;
}

// -------------------
// Interface TIntfData
// -------------------
void   TData_1::set_1( const double aValue ) { m_config.d_1 = aValue;   }
double TData_1::get_1()                      { return m_config.d_1;     }
void   TData_1::set_2( const int    aValue ) { m_config.i_2 = aValue;   }
int    TData_1::get_2()                      { return m_config.i_2;     }

void   TData_1::set_3( const double aValue ) { m_measured.d_3 = aValue; }
double TData_1::get_3()                      { return m_measured.d_3;   }
void   TData_1::set_4( const int    aValue ) { m_measured.i_4 = aValue; }
int    TData_1::get_4()                      { return m_measured.i_4;   }

void   TData_1::set_5( const double aValue ) { m_results.d_5 = aValue;  }
double TData_1::get_5()                      { return m_results.d_5;    }
void   TData_1::set_6( const int    aValue ) { m_results.i_6 = aValue;  }
int    TData_1::get_6()                      { return m_results.i_6;    }
// -------------------


// ==================================================================
Test_TData_1::Test_TData_1( std::string anId, TIntfLogger &aLogger ) :
    DUT     ( TData_1("DUT_TData_1", aLogger) ),
    m_id    ( anId    ),
    m_logger( aLogger )
{
}

void Test_TData_1::run()
{
    test_defaultInit();
    test_set_1();
    test_get_1();
    test_set_2();
    test_get_2();
    test_set_3();
    test_get_3();
    test_set_4();
    test_get_4();
    test_set_5();
    test_get_5();
    test_set_6();
    test_get_6();
}

void Test_TData_1::test_defaultInit()
{
    assert_double( DUT.m_config.d_1, 0.0 );
    assert_int   ( DUT.m_config.i_2, 0   );

    assert_double( DUT.m_measured.d_3, 0.0 );
    assert_int   ( DUT.m_measured.i_4, 0   );

    assert_double( DUT.m_results.d_5, 0.0 );
    assert_int   ( DUT.m_results.i_6, 0   );
}

void Test_TData_1::test_set_1()
{
    DUT.set_1( 123.45 );
    assert_double( DUT.m_config.d_1, 123.45 );
}

void Test_TData_1::test_get_1()
{
    DUT.m_config.d_1 = 54.321;
    assert_double( DUT.get_1(), 54.321 );
}

void Test_TData_1::test_set_2()
{
    DUT.set_2( -6 );
    assert_int( DUT.m_config.i_2, -6 );
}

void Test_TData_1::test_get_2()
{
    DUT.m_config.i_2 = 7;
    assert_int( DUT.get_2(), 7 );
}

void Test_TData_1::test_set_3()
{
    DUT.set_3( .99 );
    assert_double( DUT.m_measured.d_3, .99 );
}

void Test_TData_1::test_get_3()
{
    DUT.m_measured.d_3 = -0.354;
    assert_double( DUT.get_3(), -0.354 );
}

void Test_TData_1::test_set_4()
{
    DUT.set_4( 16 );
    assert_int( DUT.m_measured.i_4, 16 );
}

void Test_TData_1::test_get_4()
{
    DUT.m_measured.i_4 = -123;
    assert_int( DUT.get_4(), -123 );
}

void Test_TData_1::test_set_5()
{
    DUT.set_5( 12345.0926 );
    assert_double( DUT.m_results.d_5, 12345.0926 );
}

void Test_TData_1::test_get_5()
{
    DUT.m_results.d_5 = 0.012354;
    assert_double( DUT.get_5(), 0.012354 );
}

void Test_TData_1::test_set_6()
{
    DUT.set_6( 161 );
    assert_int( DUT.m_results.i_6, 161 );
}

void Test_TData_1::test_get_6()
{
    DUT.m_results.i_6 = 616;
    assert_int( DUT.get_6(), 616 );
}

// -------------------------------------------------------
void Test_TData_1::assert_double( double aD1, double aD2 )
{
    std::string s1 = std::to_string( aD1 );
    std::string s2 = std::to_string( aD2 );

    // Check results. TODO: how we compare doubles, use fcmp()
    if( s1 != s2 ) { std::cout << "[Error] " << m_id << " : " << s1 << " Expected : " << s2 << std::endl; }
    else           { std::cout << "[OK] " << m_id << std::endl;                                           }
}

void Test_TData_1::assert_int( int val_1, int val_2 )
{
    if( val_1 != val_2 ) { std::cout << "[Error] " << m_id << " : " << val_1 << " Expected : " << val_2 << std::endl; }
    else                 { std::cout << "[OK] " << m_id << std::endl;                                                 }
}
