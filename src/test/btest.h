#ifndef BTEST_H
#define BTEST_H

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

private:
    int m_run;        // Number of tests run
    int m_fail;       // Number of tests failed

    std::string m_id; // Test name
};

#endif // BTEST_H
