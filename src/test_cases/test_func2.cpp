#include "testsuite_mytests.h"


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
