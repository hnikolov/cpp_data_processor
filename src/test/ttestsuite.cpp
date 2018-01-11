#include "ttestsuite.h"


TBaseTest::TBaseTest( std::string anId, std::string aDescription ):
    m_run        (            0 ),
    m_fail       (            0 ),
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
void TBaseTest::run_test()
{
    CU_RUN(run_test_1);
}

// Example of a test
std::string TBaseTest::run_test_1()
{
    CU_ASSERT_EQ( 1, 1, "Condition 1" );
    CU_ASSERT_EQ( 1, 1, "Condition 2" );

    return ""; // Return an empty string if all asserts OK
}

std::string TBaseTest::getResultMessage()
{
    std::ostringstream result_msg;
    result_msg << "Run: " << m_run ;

    if( m_fail > 0 ) { result_msg << " .. (" << m_fail << "-)"; }
    else             { result_msg << " .. OK"                 ; }

    return result_msg.str();
}

//---------------------------------------------------------------
Test_Func1::Test_Func1( std::string anId, std::string aDescription ):
    TBaseTest( anId, aDescription )
{
}

void Test_Func1::run_test()
{
    CU_RUN(run_test_1);
    CU_RUN(run_test_1);
    CU_RUN(run_test_1);
    CU_RUN(run_test_1);
}

std::string Test_Func1::run_test_1()
{
    CU_ASSERT_EQ( 1.12, 1.12, "Condition 1" );
    CU_ASSERT_EQ( 1,    1,    "Condition 2" );

    return ""; // Return an empty string if all asserts OK
}

//---------------------------------------------------------------
Test_Func2::Test_Func2( std::string anId, std::string aDescription ):
    TBaseTest( anId, aDescription )
{
}

void Test_Func2::run_test()
{
    CU_RUN(run_test_1);
    CU_RUN(run_test_2);
}

std::string Test_Func2::run_test_1()
{
    CU_ASSERT_EQ( 1.112, 1.12, "Condition 1" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_Func2::run_test_2()
{
    CU_ASSERT_EQ( -3, -3, "Condition -3" );
    return ""; // Return an empty string if all asserts OK
}

// ======================================================================

TTestSuite::TTestSuite(std::string anId, TIntfLogger &aLogger):
    m_run   (       0 ),
    m_fail  (       0 ),
    m_id    (    anId ),
    m_logger( aLogger )
{
}

std::string TTestSuite::getResultMessage()
{
    std::ostringstream result_msg;
    result_msg << "Total Run: " << m_run ;

    if( m_fail > 0 ) { result_msg << " .. (" << m_fail << "-)"; }
    else             { result_msg << " .. OK";               }

    return result_msg.str();
}

void TTestSuite::run_all()
{
    m_logger.log( "Executing tests...", m_id );
    // TODO: Filter tests to be run
    for( TBaseTest* t : m_tests )
    {
        t->run_test();
        m_logger.log( t->getResultMessage(), t->getId() );
        m_run  += t->getRun();
        m_fail += t->getFail();
    }
    // if (VERBOSE)
    m_logger.log( getResultMessage(), m_id );
}

// =======================================================================

// TODO Use unique pointers std::unique_ptr<TBaseTest> or define destructor

TTestSuite_myTests::TTestSuite_myTests(std::string anId, TIntfLogger &aLogger):
    TTestSuite( anId, aLogger )
{
    m_tests.push_back( new TBaseTest("myFirst") );
    m_tests.push_back( new Test_Func1("myFunc1", "Test description goes here.") );
    m_tests.push_back( new Test_Func2("myFunc2", "Test description goes here.") );
}
