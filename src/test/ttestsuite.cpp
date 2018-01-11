#include "ttestsuite.h"


TBaseTest::TBaseTest( std::string anId, std::string aDescription ):
    m_id         (         anId ),
    m_description( aDescription )
{
}

TBaseTest::~TBaseTest()
{
    std::cout << "[" << m_id << "] " << "Destructor called" << std::endl;
}

template <typename T>
void TBaseTest::setAssertMessage( T anExpected, T aDetected, std::string anId )
{
    m_assert_msg.str("");   // Clear the content, so variable can be reused
    m_assert_msg << m_id << ", "  << anId
                 << ", wrong value"
                 << ", expected " << anExpected
                 << ", detected " << aDetected
                 << std::endl;
}

// Example of how to build a test. To be overriden
std::string TBaseTest::run_test()
{
    CU_ASSERT_EQ( 1, 1, "Condition 1" );
    CU_ASSERT_EQ( 1, 1, "Condition 2" );

    return ""; // Return an empty string if all asserts OK
}
//---------------------------------------------------------------
Test_Func1::Test_Func1( std::string anId, std::string aDescription ):
    TBaseTest( anId, aDescription )
{
}

std::string Test_Func1::run_test()
{
    CU_ASSERT_EQ( 1.12, 1.12, "Condition 1" );
    CU_ASSERT_EQ( 1,    1,    "Condition 2" );

    return ""; // Return an empty string if all asserts OK
}


// ======================================================================

TTestSuite::TTestSuite(std::string anId, TIntfLogger &aLogger):
    m_run (     0),
    m_fail(     0),
    m_id  ( anId ),
    m_logger( aLogger )
{
}

std::string TTestSuite::getResultMessage()
{
    std::ostringstream result_msg;
//    result_msg << "[Run]: " << m_id << " (" << m_run  << ")";
//    if( m_fail > 0 ) { result_msg << " (" << m_fail << "-)" << std::endl; }
//    else             { result_msg << std::endl; }

    result_msg << "Run: " << m_run ;

    if( m_fail > 0 ) { result_msg << " (" << m_fail << "-)"; }

    return result_msg.str();
}

void TTestSuite::run_all()
{
    // TODO: Filter tests to be run
    for( TBaseTest* t : m_tests )
    {
        CU_RUN(t->run_test);
        std::cout << ".";
    }
    std::cout << std::endl;
    // if (VERBOSE)
    //std::cout << getResultMessage();
    m_logger.log( getResultMessage(), m_id );
}

// =======================================================================

// TODO Use unique pointers std::unique_ptr<TBaseTest> or define destructor

TTestSuite_myTests::TTestSuite_myTests(std::string anId, TIntfLogger &aLogger):
    TTestSuite( anId, aLogger )
{
    m_tests.push_back( new TBaseTest("myFirst"));
    m_tests.push_back( new TBaseTest("mySecond"));
    m_tests.push_back( new Test_Func1("myFunc1", "Test description goes here."));
}
