#include "ttest.h"


TTest::TTest( std::string anId ):
    BTest( anId )
{
}

void TTest::setSubTestName( std::string aName )
{
    m_SubTestId = aName;
}

std::string TTest::getAssertMessage( std::string anExpected, std::string aDetected, std::string anId )
{
    std::ostringstream assert_msg;
    assert_msg << m_SubTestId << "(), " << anId       << ", wrong value"
               << ", expected "         << anExpected
               << ", detected "         << aDetected
               << std::endl;

    return assert_msg.str();
}

// Example of how to build and run a test. To be overriden
void TTest::execute()
{
    CU_RUN( run_test_1 );
}

// Example of a test. This test fails on purpose.
std::string TTest::run_test_1()
{
    CU_ASSERT_EQ( 1, 0, "Example test called - should not happen." );
    return ""; // Return an empty string if all asserts OK
}
