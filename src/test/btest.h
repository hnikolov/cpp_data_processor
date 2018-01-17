#ifndef BTEST_H
#define BTEST_H

#include "cu_macros.h"

#include <iostream>
#include <sstream>


class BTest
{
public:
    explicit BTest( std::string anId );
    ~BTest();

    virtual void execute() = 0;

    std::string getId  ();
    int         getRun ();
    int         getFail();
    void        incRun ( const int anInc = 1 );
    void        incFail( const int anInc = 1 );

    std::string getResultMessage();
    std::string getAssertMessage( std::string anExpected, std::string aDetected, std::string anId );
    void        setSubTestName  ( std::string aName );

private:
    int m_run;  // Number of tests run
    int m_fail; // Number of tests failed

    std::string m_id;        // Test name
    std::string m_SubTestId; // Set to the current test/function name running a test
};

#endif // BTEST_H
