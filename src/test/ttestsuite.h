#ifndef TTESTSUITE_H
#define TTESTSUITE_H

#include "btest.h"

#include "../ilogger.h"

#include <iostream>
#include <vector>
#include <memory>

typedef std::unique_ptr< BTest > UPtrBaseTest;


class TTestSuite : public BTest
{
public:
    TTestSuite( std::string anId, ILogger &aLogger );

    virtual void execute();

    void add( BTest *aTest );
    void logResults();

private:
    std::vector< UPtrBaseTest > m_tests;

    ILogger & m_logger;
};

#endif // TTESTSUITE_H
