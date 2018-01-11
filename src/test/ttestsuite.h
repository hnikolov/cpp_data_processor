#ifndef TTESTSUITE_H
#define TTESTSUITE_H

#include "../tintflogger.h"

#include <iostream>
#include <sstream>
#include <vector>

// MACROS ---------------------------------------------------
// NOTE: Only 1 assert fails per test because we return
// m_fail++; removed
#define CU_ASSERT( condition, message ) do                   \
{                                                            \
    if((condition) == false) {                               \
        return message;                                      \
    }                                                        \
}   while (0)


#define CU_ASSERT_EQ( anExpected, aDetected, aCndName ) do   \
{                                                            \
    setAssertMessage( anExpected, aDetected, aCndName );     \
                                                             \
    std::string s1 = std::to_string( anExpected );           \
    std::string s2 = std::to_string(  aDetected );           \
    bool condition = (s1 == s2);                             \
                                                             \
    CU_ASSERT( condition, getAssertMessage() );              \
}   while(0)


// TODO: Use m_description as well?
// Called by TestSuite
#define CU_RUN( function ) do                                \
{                                                            \
    std::string message = function();                        \
    m_run++;                                                 \
    if( message != "" )                                      \
    {                                                        \
        m_fail++;                                            \
        std::cout << "[Error]: Test " << m_run << std::endl  \
                  << "         " << message    << std::endl; \
    }                                                        \
}   while (0)
// ----------------------------------------------------------


class TBaseTest
{
public:
    explicit TBaseTest( std::string anId, std::string aDescription = "" );
    virtual ~TBaseTest();

    virtual std::string run_test();

    void        setDescription( std::string aDescription ) { m_description = aDescription; }
    std::string getDescription()                           { return m_description;         }

    template <typename T>
    void setAssertMessage( T anExpected, T aDetected, std::string anId );

    std::string getAssertMessage() { return m_assert_msg.str(); }

private:
    std::ostringstream m_assert_msg;

    std::string m_id;
    std::string m_description;
};

//-------------------------------------------------------------------------
class Test_Func1 : public TBaseTest
{
public:
    Test_Func1( std::string anId, std::string aDescription = "" );

    virtual std::string run_test();
};

// ===========================================================================================
class TTestSuite
{
public:
    TTestSuite( std::string anId, TIntfLogger &aLogger );

    void run_all();

    std::string getResultMessage();

    std::vector< TBaseTest* > m_tests;

private:
    int m_run;  // Number of tests run
    int m_fail; // Number of tests fail

    std::string   m_id; // TODO: Test description?
    TIntfLogger & m_logger;
};

// --------------------------------
class TTestSuite_myTests : public TTestSuite
{
public:
    TTestSuite_myTests( std::string anId, TIntfLogger &aLogger );

    void run_all();
};

#endif // TTESTSUITE_H
