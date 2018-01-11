#include "ttestsuite.h"


TBaseTest::TBaseTest( std::string anId, std::string aDescription ):
    m_run        (            0 ),
    m_fail       (            0 ),
    m_id         (         anId ),
    m_description( aDescription )
{
}

//TBaseTest::~TBaseTest() { std::cout << "[" << m_id << "] " << "Destructor called" << std::endl; }

std::string TBaseTest::getAssertMessage( std::string anExpected, std::string aDetected, std::string anId )
{
    std::ostringstream assert_msg;
    assert_msg << m_id << ", "  << anId
               << ", wrong value"
               << ", expected " << anExpected
               << ", detected " << aDetected
               << std::endl;

    return assert_msg.str();
}

// Example of how to build a test. To be overriden
void TBaseTest::execute()
{
    CU_RUN( run_test_1 );
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

void Test_Func1::execute()
{
    CU_RUN( run_test_1 );
    CU_RUN( run_test_1 ); // Just as an example...
    CU_RUN( run_test_1 );
    CU_RUN( run_test_1 );
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

void Test_Func2::execute()
{
    CU_RUN( run_test_1 );
    CU_RUN( run_test_2 );
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

/*
void TTestSuite::run_all()
{
    m_logger.log( "Executing tests...", m_id );
    // TODO: Filter tests to be run
    for( TBaseTest* t : m_tests )
    {
        t->execute();
        m_logger.log( t->getResultMessage(), t->getId() );
        m_run  += t->getRun();
        m_fail += t->getFail();
    }
    // if (VERBOSE)
    m_logger.log( getResultMessage(), m_id );
}
/*/
void TTestSuite::run_all()
{
    m_logger.log( "Executing tests...", m_id );
    // TODO: Filter tests to be run

    for( auto&& t : m_tests )
    {
        t->execute();
        m_logger.log( t->getResultMessage(), t->getId() );
        m_run  += t->getRun();
        m_fail += t->getFail();
    }
    // if (VERBOSE)
    m_logger.log( getResultMessage(), m_id );
}
//*/
// =======================================================================

TTestSuite_myTests::TTestSuite_myTests(std::string anId, TIntfLogger &aLogger):
    TTestSuite( anId, aLogger )
{
/*
    m_tests.push_back( new TBaseTest("myFirst") );
    m_tests.push_back( new Test_Func1("myFunc1", "Test description goes here.") );
    m_tests.push_back( new Test_Func2("myFunc2", "Test description goes here.") );
    m_tests.push_back( new Test_TData_1_1("TData1") );

/*/
//    std::unique_ptr<TBaseTest> myFunc2_U (new Test_Func2("myFunc2_U"));
//    m_tests.push_back( move(myFunc2_U));

    //typedef std::unique_ptr<int> Ptr;
    //std::vector<Ptr> v;

    m_tests.push_back( std::unique_ptr<TBaseTest> (new TBaseTest("myFirst_U")));
    m_tests.push_back( std::unique_ptr<TBaseTest> (new Test_Func1("myFunc1_U", "Test description goes here.")));
    m_tests.push_back( std::unique_ptr<TBaseTest> (new Test_Func2("myFunc2_U")));
    m_tests.push_back( std::unique_ptr<TBaseTest> (new Test_TData_1_1("TData1_U")));
//*/
}

// *************************************************************************
// *************************************************************************
Test_TData_1_1::Test_TData_1_1( std::string anId ) :
    TBaseTest( anId ),
    DUT      ( TData_1("DUT_TData_1_1", m_logger) )
{
}

void Test_TData_1_1::execute()
{
    CU_RUN( test_defaultInit );
    CU_RUN( test_set_1 );
    CU_RUN( test_get_1 );
    CU_RUN( test_set_2 );
    CU_RUN( test_get_2 );
    CU_RUN( test_set_3 );
    CU_RUN( test_get_3 );
    CU_RUN( test_set_4 );
    CU_RUN( test_get_4 );
    CU_RUN( test_set_5 );
    CU_RUN( test_get_5 );
    CU_RUN( test_set_6 );
    CU_RUN( test_get_6 );
}

std::string Test_TData_1_1::test_defaultInit()
{
    CU_ASSERT_EQ( DUT.m_config.d_1, 0.0, "d_1" );
    CU_ASSERT_EQ( DUT.m_config.i_2, 0,   "i_2" );

    CU_ASSERT_EQ( DUT.m_measured.d_3, 0.0, "d_3" );
    CU_ASSERT_EQ( DUT.m_measured.i_4, 0,   "i_4" );

    CU_ASSERT_EQ( DUT.m_results.d_5, 0.0, "d_5" );
    CU_ASSERT_EQ( DUT.m_results.i_6, 0,   "i_6" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_set_1()
{
    DUT.set_1( 123.45 );
    CU_ASSERT_EQ( DUT.m_config.d_1, 123.45, "Set d_1" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_get_1()
{
    DUT.m_config.d_1 = 54.321;
    CU_ASSERT_EQ( DUT.get_1(), 54.321, "Get d_1" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_set_2()
{
    DUT.set_2( -6 );
    CU_ASSERT_EQ( DUT.m_config.i_2, -6, "Set i_2" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_get_2()
{
    DUT.m_config.i_2 = 7;
    CU_ASSERT_EQ( DUT.get_2(), 7, "Get i_2" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_set_3()
{
    DUT.set_3( .99 );
    CU_ASSERT_EQ( DUT.m_measured.d_3, .99, "Set d_3" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_get_3()
{
    DUT.m_measured.d_3 = -0.354;
    CU_ASSERT_EQ( DUT.get_3(), -0.354, "Get d_3" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_set_4()
{
    DUT.set_4( 16 );
    CU_ASSERT_EQ( DUT.m_measured.i_4, 16, "Set i_4" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_get_4()
{
    DUT.m_measured.i_4 = -123;
    CU_ASSERT_EQ( DUT.get_4(), -123, "Get i_4" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_set_5()
{
    DUT.set_5( 12345.0926 );
    CU_ASSERT_EQ( DUT.m_results.d_5, 12345.0926, "Set d_5" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_get_5()
{
    DUT.m_results.d_5 = 0.012354;
    CU_ASSERT_EQ( DUT.get_5(), 0.012354, "Get d_5" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_set_6()
{
    DUT.set_6( 161 );
    CU_ASSERT_EQ( DUT.m_results.i_6, 161, "Set i_6" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1_1::test_get_6()
{
    DUT.m_results.i_6 = 616;
    CU_ASSERT_EQ( DUT.get_6(), 616, "Get i_6" );
    return ""; // Return an empty string if all asserts OK
}
