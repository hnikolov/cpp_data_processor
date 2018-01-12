#include "testsuite_mytests.h"

Test_TData_1::Test_TData_1( std::string anId ) :
    TBaseTest( anId ),
    DUT      ( TData_1("DUT_TData_1_1", m_logger) )
{
}

void Test_TData_1::execute()
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

std::string Test_TData_1::test_defaultInit()
{
    CU_ASSERT_EQ( DUT.m_config.d_1, 0.0, "d_1" );
    CU_ASSERT_EQ( DUT.m_config.i_2, 0,   "i_2" );

    CU_ASSERT_EQ( DUT.m_measured.d_3, 0.0, "d_3" );
    CU_ASSERT_EQ( DUT.m_measured.i_4, 0,   "i_4" );

    CU_ASSERT_EQ( DUT.m_results.d_5, 0.0, "d_5" );
    CU_ASSERT_EQ( DUT.m_results.i_6, 0,   "i_6" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_set_1()
{
    DUT.set_1( 123.45 );
    CU_ASSERT_EQ( DUT.m_config.d_1, 123.45, "Set d_1" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_get_1()
{
    DUT.m_config.d_1 = 54.321;
    CU_ASSERT_EQ( DUT.get_1(), 54.321, "Get d_1" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_set_2()
{
    DUT.set_2( -6 );
    CU_ASSERT_EQ( DUT.m_config.i_2, -6, "Set i_2" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_get_2()
{
    DUT.m_config.i_2 = 7;
    CU_ASSERT_EQ( DUT.get_2(), 7, "Get i_2" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_set_3()
{
    DUT.set_3( .99 );
    CU_ASSERT_EQ( DUT.m_measured.d_3, .99, "Set d_3" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_get_3()
{
    DUT.m_measured.d_3 = -0.354;
    CU_ASSERT_EQ( DUT.get_3(), -0.354, "Get d_3" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_set_4()
{
    DUT.set_4( 16 );
    CU_ASSERT_EQ( DUT.m_measured.i_4, 16, "Set i_4" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_get_4()
{
    DUT.m_measured.i_4 = -123;
    CU_ASSERT_EQ( DUT.get_4(), -123, "Get i_4" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_set_5()
{
    DUT.set_5( 12345.0926 );
    CU_ASSERT_EQ( DUT.m_results.d_5, 12345.0926, "Set d_5" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_get_5()
{
    DUT.m_results.d_5 = 0.012354;
    CU_ASSERT_EQ( DUT.get_5(), 0.012354, "Get d_5" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_set_6()
{
    DUT.set_6( 161 );
    CU_ASSERT_EQ( DUT.m_results.i_6, 161, "Set i_6" );
    return ""; // Return an empty string if all asserts OK
}

std::string Test_TData_1::test_get_6()
{
    DUT.m_results.i_6 = 616;
    CU_ASSERT_EQ( DUT.get_6(), 616, "Get i_6" );
    return ""; // Return an empty string if all asserts OK
}
