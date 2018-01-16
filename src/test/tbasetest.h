#ifndef TBASETEST_H
#define TBASETEST_H

#include <iostream>
#include <sstream>

// Not used
#define SET_SUB_TEST_NAME() (chr_pSubTestName = __FUNCTION__)

// MACROS ------------------------------------------------------
// NOTE: Only 1 assert fails per test because we return
// -------------------------------------------------------------
#define CU_ASSERT_EQ( anExpected, aDetected, aCndName ) do     \
{                                                              \
    m_SubTestId = __FUNCTION__;                                \
                                                               \
    std::string s1       = std::to_string( anExpected );       \
    std::string s2       = std::to_string(  aDetected );       \
    std::string asrt_msg = getAssertMessage(s1, s2, aCndName); \
                                                               \
    bool condition = (s1 == s2);                               \
                                                               \
    if( condition == false ) { return asrt_msg; }              \
                                                               \
}   while(0)


// Called by execute()
// TODO: Init()/Deinit() before/after each function()?
#define CU_RUN( function ) do                                  \
{                                                              \
    std::string message = function();                          \
    m_run++;                                                   \
    if( message != "" )                                        \
    {                                                          \
        m_fail++;                                              \
        std::cout << "[Error]: Test " << m_run                 \
                  <<           " of " << m_id    << std::endl  \
                  << "         "      << message << std::endl; \
    }                                                          \
}   while (0)
// -------------------------------------------------------------


class TBaseTest
{
public:
    explicit TBaseTest( std::string anId, std::string aDescription = "" );
    ~TBaseTest();

    virtual void execute();

    std::string getId()   { return m_id;   }
    int         getRun()  { return m_run;  }
    int         getFail() { return m_fail; }

    std::string getAssertMessage( std::string anExpected, std::string aDetected, std::string anId );
    std::string getResultMessage();

    // TODO: How useful is this?
    void        setDescription( std::string aDescription ) { m_description = aDescription; }
    std::string getDescription()                           { return m_description;         }

protected:
    int m_run;  // Number of tests run
    int m_fail; // Number of tests failed

    std::string m_id;        // Test name. A test may run one or more test functions
    std::string m_SubTestId; // Set to the current test/function name running a test

private:
    std::string run_test_1();  // This test fails on purpose - base class test should not be called

    std::string m_description; // TODO
};

#endif // TBASETEST_H
