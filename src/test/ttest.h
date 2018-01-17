#ifndef TTEST_H
#define TTEST_H

#include "btest.h"
#include "cu_macros.h"

#include <iostream>
#include <sstream>


class TTest : public BTest
{
public:
    explicit TTest( std::string anId );

    virtual void execute();

    void         setSubTestName  ( std::string aName );
    std::string  getAssertMessage( std::string anExpected, std::string aDetected, std::string anId );

private:
    std::string  run_test_1(); // Example test, fails on purpose - this test should not be called

    std::string  m_SubTestId;  // Set to the current test/function name running a test
};

#endif // TTEST_H
