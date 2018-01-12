#include "tbasetest.h"


TBaseTest::TBaseTest( std::string anId, std::string aDescription ):
    m_run        (            0 ),
    m_fail       (            0 ),
    m_id         (         anId ),
    m_description( aDescription )
{
}

TBaseTest::~TBaseTest() { std::cout << "[" << m_id << "] " << "Destructor called" << std::endl; }

std::string TBaseTest::getAssertMessage( std::string anExpected, std::string aDetected, std::string anId )
{
    std::ostringstream assert_msg;
    assert_msg << m_id << ", "  << anId       << ", wrong value"
               << ", expected " << anExpected
               << ", detected " << aDetected
               << std::endl;

    return assert_msg.str();
}

std::string TBaseTest::getResultMessage()
{
    std::ostringstream result_msg;
    result_msg << "Run: " << m_run ;

    if( m_fail > 0 ) { result_msg << " .. (" << m_fail << "-)"; }
    else             { result_msg << " .. OK"                 ; }

    return result_msg.str();
}

// Example of how to build a test. To be overriden
void TBaseTest::execute()
{
    CU_RUN( run_test_1 );
}

// Example of a test. This test fails on purpose.
std::string TBaseTest::run_test_1()
{
    CU_ASSERT_EQ( 1, 0, "Base class test called. Should not happen." );
    return ""; // Return an empty string if all asserts OK
}
