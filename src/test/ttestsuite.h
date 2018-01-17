#ifndef TTESTSUITE_H
#define TTESTSUITE_H

#include "btest.h"
#include "ttest.h"

#include "../ilogger.h"

#include <iostream>
#include <vector>
#include <memory>

typedef std::unique_ptr< TTest > UPtrBaseTest;


class TTestSuite : public BTest
{
public:
    TTestSuite( std::string anId, ILogger &aLogger );

    virtual void execute();

    void add( TTest *aTest );

private:
    std::vector< UPtrBaseTest > m_tests;

    ILogger & m_logger;
};

#endif // TTESTSUITE_H
