#include "test_example.h"


TestExample::TestExample( std::string anId ):
    BTest( anId )
{
}

// Example of how to build and run a test
void TestExample::execute()
{
    CU_RUN( run_test_1 );
    CU_RUN( run_test_2 );
}

// Example of a test. This test succeeds
std::string TestExample::run_test_1()
{
    CU_ASSERT_EQ(  1.2, 1.2, "Condition 1.2" );
    CU_ASSERT_EQ( -3,  -3,   "Condition -3"  );
    return ""; // Return an empty string if all asserts OK
}

// Example of a test. This test fails on purpose.
std::string TestExample::run_test_2()
{
    CU_ASSERT_EQ( 1, 0, "Example test expected to fail." );
    return ""; // Return an empty string if all asserts OK
}
