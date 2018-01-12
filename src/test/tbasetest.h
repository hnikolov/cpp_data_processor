#ifndef TBASETEST_H
#define TBASETEST_H

#include <iostream>
#include <sstream>

// MACROS ------------------------------------------------------
// NOTE: Only 1 assert fails per test because we return
// -------------------------------------------------------------
#define CU_ASSERT_EQ( anExpected, aDetected, aCndName ) do     \
{                                                              \
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
    ~TBaseTest();

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
    int m_fail; // Number of tests failed

private:
    std::string run_test_1(); // This test fails on purpose - base class test should not be called

    std::string m_id;
    std::string m_description;
};

#endif // TBASETEST_H
