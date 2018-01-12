#ifndef TEST_CASES_H
#define TEST_CASES_H

#include "../test/tbasetest.h"
#include "../test/ttestsuite.h"

#include "../tdata_1.h"
#include "../tlogger_1.h"

//-------------------------------------------------------------------------
class Test_TData_1 : public TBaseTest
{
public:
    Test_TData_1( std::string anId );
    virtual void execute();

private:
    TData_1 DUT;

    // Tests
    std::string test_defaultInit();
    std::string test_set_1(); // Configure
    std::string test_get_1();
    std::string test_set_2();
    std::string test_get_2();
    std::string test_set_3(); // Runtime
    std::string test_get_3();
    std::string test_set_4();
    std::string test_get_4();
    std::string test_set_5(); // Results
    std::string test_get_5();
    std::string test_set_6();
    std::string test_get_6();

    TLogger_1 m_logger; // for DUT, not used
};

//-------------------------------------------------------------------------
class Test_Func1 : public TBaseTest
{
public:
    Test_Func1( std::string anId, std::string aDescription = "" );
    virtual void execute();

private:
    std::string run_test_1();
    std::string run_test_2();
    std::string run_test_3();
    std::string run_test_4();
};

//-------------------------------------------------------------------------
class Test_Func2 : public TBaseTest
{
public:
    Test_Func2( std::string anId, std::string aDescription = "" );
    virtual void execute();

private:
    std::string run_test_1();
    std::string run_test_2();
};

//==========================================================================
class TTestSuite_myTests : public TTestSuite
{
public:
    TTestSuite_myTests( std::string anId, ILogger &aLogger );
};

#endif // TEST_CASES_H
