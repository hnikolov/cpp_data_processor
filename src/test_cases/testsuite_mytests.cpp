#include "testsuite_mytests.h"


TTestSuite_myTests::TTestSuite_myTests(std::string anId, TIntfLogger &aLogger):
    TTestSuite( anId, aLogger )
{
    m_tests.push_back( UPtrBaseTest(new TBaseTest   ("myFirst"))); // Should not call base class test
    m_tests.push_back( UPtrBaseTest(new Test_Func1  ("myFunc1", "Test description goes here.")));
    m_tests.push_back( UPtrBaseTest(new Test_Func2  ("myFunc2")));
    m_tests.push_back( UPtrBaseTest(new Test_TData_1("TData_1")));
}
