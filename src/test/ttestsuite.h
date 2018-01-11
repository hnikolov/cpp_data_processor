#ifndef TTESTSUITE_H
#define TTESTSUITE_H

#include "../tintflogger.h"

#include <iostream>
#include <sstream>
#include <vector>

// MACROS ------------------------------------------------------
// NOTE: Only 1 assert fails per test because we return
// -------------------------------------------------------------
#define CU_ASSERT( condition, message ) do                     \
{                                                              \
    if((condition) == false) {                                 \
        return message;                                        \
    }                                                          \
}   while (0)


#define CU_ASSERT_EQ( anExpected, aDetected, aCndName ) do     \
{                                                              \
    std::string s1       = std::to_string( anExpected );       \
    std::string s2       = std::to_string(  aDetected );       \
    std::string asrt_msg = getAssertMessage(s1, s2, aCndName); \
                                                               \
    bool condition = (s1 == s2);                               \
                                                               \
    CU_ASSERT( condition, asrt_msg );                          \
}   while(0)


// TODO: Use m_description as well?
// Called by TestSuite
#define CU_RUN( function ) do                                  \
{                                                              \
    std::string message = function();                          \
    m_run++;                                                   \
    if( message != "" )                                        \
    {                                                          \
        m_fail++;                                              \
        std::cout << "[Error]: Test " <<   m_run << std::endl  \
                  << "         "      << message << std::endl; \
    }                                                          \
}   while (0)
// -------------------------------------------------------------


class TBaseTest
{
public:
    explicit TBaseTest( std::string anId, std::string aDescription = "" );
//    virtual ~TBaseTest();

    virtual void execute();

    void        setDescription( std::string aDescription ) { m_description = aDescription; }
    std::string getDescription()                           { return m_description;         }
    std::string getId()                                    { return m_id;                  }

    std::string getAssertMessage( std::string anExpected, std::string aDetected, std::string anId );
    std::string getResultMessage();

    int getRun()  { return m_run;  }
    int getFail() { return m_fail; }

protected:
    int m_run;  // Number of tests run
    int m_fail; // Number of tests fail

private:
    std::string run_test_1(); // TODO: just an example

    std::string m_id;
    std::string m_description;
};

//-------------------------------------------------------------------------
class Test_Func1 : public TBaseTest
{
public:
    Test_Func1( std::string anId, std::string aDescription = "" );

    virtual void execute();

private:
    std::string run_test_1();
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

// ===========================================================================================
#include <memory>

class TTestSuite
{
public:
    TTestSuite( std::string anId, TIntfLogger &aLogger );

    void run_all();

    std::string getResultMessage();

/*
    std::vector< TBaseTest* > m_tests;
/*/
    std::vector< std::unique_ptr<TBaseTest> > m_tests;
//*/

private:
    int m_run;  // Number of tests run
    int m_fail; // Number of tests failed

    std::string   m_id; // TODO: Test description?
    TIntfLogger & m_logger;
};

// --------------------------------
class TTestSuite_myTests : public TTestSuite
{
public:
    TTestSuite_myTests( std::string anId, TIntfLogger &aLogger );
};

// *******************************************************************************
// *******************************************************************************

#include "../tdata_1.h"
#include "../tlogger_1.h"

class Test_TData_1_1 : public TBaseTest
{
public:
    Test_TData_1_1( std::string anId );

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
#endif // TTESTSUITE_H
