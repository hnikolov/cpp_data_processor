#include "tdata_1.h"
#include <iostream>

TData_1::TData_1( std::string anId, ILogger &aLogger ) :
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
// Interface IData
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
