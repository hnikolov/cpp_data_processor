#include "btest.h"

BTest::BTest( std::string anId ) :
    m_run (    0 ),
    m_fail(    0 ),
    m_id  ( anId )
{
}

BTest::~BTest()  { std::cout << "[" << m_id << "] " << "Destructor called" << std::endl; }

std::string BTest::getId  ()                  { return m_id;     }
int         BTest::getRun ()                  { return m_run;    }
int         BTest::getFail()                  { return m_fail;   }
void        BTest::incRun ( const int anInc ) { m_run  += anInc; }
void        BTest::incFail( const int anInc ) { m_fail += anInc; }

std::string BTest::getResultMessage()
{
    std::ostringstream result_msg;
    result_msg << "Run: " << m_run ;

    if( m_fail > 0 ) { result_msg << " .. (" << m_fail << "-)"; }
    else             { result_msg << " .. OK"                 ; }

    return result_msg.str();
}
