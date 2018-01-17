#include "testsuite_mytests.h"


Test_Func1::Test_Func1( std::string anId ):
    TTest( anId )
{
}

void Test_Func1::execute()
{
    CU_RUN( run_test_1 );
    CU_RUN( run_test_2 );
    CU_RUN( run_test_3 );
    CU_RUN( run_test_4 );
}

std::string Test_Func1::run_test_1()
{
    CU_ASSERT_EQ( 1.12, 1.12, "Condition 1" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_Func1::run_test_2()
{
    CU_ASSERT_EQ( 2, 2, "Condition 2" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_Func1::run_test_3()
{
    CU_ASSERT_EQ( 1.12, 1.12, "Condition 1" );
    CU_ASSERT_EQ( 1,    1,    "Condition 2" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_Func1::run_test_4()
{
    CU_ASSERT_EQ(  -.12,   -.12,  "Condition 1" );
    CU_ASSERT_EQ( -0.321, -0.321, "Condition 2" );
    return ""; // Return an empty string if all asserts OK
}
