#include "testsuite_mytests.h"


TTestSuite_myTests::TTestSuite_myTests(std::string anId, TIntfLogger &aLogger):
    TTestSuite( anId, aLogger )
{
/*
    m_tests.push_back( new TBaseTest("myFirst") );
    m_tests.push_back( new Test_Func1("myFunc1", "Test description goes here.") );
    m_tests.push_back( new Test_Func2("myFunc2", "Test description goes here.") );
    m_tests.push_back( new Test_TData_1_1("TData1") );

/*/
    m_tests.push_back( UPtrBaseTest(new TBaseTest     ("myFirst_U"))); // Should not call base class test
    m_tests.push_back( UPtrBaseTest(new Test_Func1    ("myFunc1_U", "Test description goes here.")));
    m_tests.push_back( UPtrBaseTest(new Test_Func2    ("myFunc2_U")));
    m_tests.push_back( UPtrBaseTest(new Test_TData_1_1("TData1_U" )));
//*/
}
