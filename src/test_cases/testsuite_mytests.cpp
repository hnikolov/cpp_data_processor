#include "testsuite_mytests.h"


TTestSuite_myTests::TTestSuite_myTests(std::string anId, ILogger &aLogger):
    TTestSuite( anId, aLogger )
{
    add( new TBaseTest   ( "myFirst" )); // Should not call base class test
    add( new Test_Func1  ( "myFunc1" ));
    add( new Test_Func2  ( "myFunc2" ));
    add( new Test_TData_1( "TData_1" ));
}
