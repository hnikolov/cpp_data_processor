#ifndef TTESTSUITE_H
#define TTESTSUITE_H

#include "tbasetest.h"

#include "../ilogger.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

typedef std::unique_ptr<TBaseTest> UPtrBaseTest;

class TTestSuite
{
public:
    TTestSuite( std::string anId, ILogger &aLogger );

    void run_all();

    std::string getResultMessage();

protected:
    std::vector< UPtrBaseTest > m_tests;

private:
    int m_run;  // Number of tests run
    int m_fail; // Number of tests failed

    std::string   m_id; // TODO: Test description?
    ILogger     & m_logger;
};

#endif // TTESTSUITE_H
