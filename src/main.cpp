#include "tdata_1.h"
#include "tdata_map.h"
#include "tprocessor_1.h"
#include "tlogger_1.h"
#include "tdataprocessor_1.h"
#include "tdpimplementation_1.h"

#include "test_cases/testsuite_mytests.h"

#include <iostream>
#include <vector>


TLogger_1 myLogger;

void assert_double( double aD1, double aD2, std::string aMsg = "" )
{
    std::string s1 = std::to_string( aD1 );
    std::string s2 = std::to_string( aD2 );

    // Check results. TODO: how we compare doubles, use fcmp()
    if( s1 != s2 )
    {
        std::cout << "[Error] " << aMsg << " : " << s1 << " Expected : " << s2 << std::endl;
    }
    else
    {
        std::cout << "[OK] " << aMsg << std::endl;
    }
}

void simple_use( IDataProcessor & myDataProcessor, double aDouble, int anInt, bool aLogEn = true )
{
    myDataProcessor.enable_log( aLogEn );

    myLogger.log("Initial Result    : " + std::to_string( myDataProcessor.get_5() ), "Main");
    myLogger.log("Set Configuration : " + std::to_string( aDouble                 ), "Main");
    myLogger.log("Set Runtime data  : " + std::to_string( anInt                   ), "Main");

    // Use the data processor
    myDataProcessor.set_1( aDouble );
    myDataProcessor.set_4( anInt );
    myDataProcessor.calculate_1();

    myLogger.log("Result            : " + std::to_string( myDataProcessor.get_5() ), "Main");

    assert_double( myDataProcessor.get_5(), (aDouble + anInt), myDataProcessor.getId());

    if( aLogEn == true ) { std::cout << std::endl; }
}

// Factory approach: use pointers
TDataProcessor_2* create_2( std::string anId, ILogger &aLogger )
{
    std::string sdata = anId + "_data";
    std::string sproc = anId + "_proc";

    TData_1* myData = new TData_1( sdata, aLogger );
    return new TDataProcessor_2( anId, myData, new TProcessor_1( sproc, *myData, aLogger ), aLogger );
}

// Factory approach: use smart pointers
std::unique_ptr<IDataProcessor> create_3( std::string anId, ILogger &aLogger )
{
    std::string sdata = anId + "_data";
    std::string sproc = anId + "_proc";

    std::unique_ptr<TData_1>          myData (new TData_1( sdata, aLogger ) );
    std::unique_ptr<TProcessor_1>     myProc (new TProcessor_1( sproc, *myData, aLogger ));
    std::unique_ptr<TDataProcessor_3> myDataProc (new TDataProcessor_3( anId, move(myData), move(myProc), aLogger ));
    return myDataProc;
}

// Using smart pointers and TData_map
std::unique_ptr<IDataProcessor> create_4( std::string anId, ILogger &aLogger )
{
    std::string sdata = anId + "_data";
    std::string sproc = anId + "_proc";

    std::unique_ptr<TData_map>        myData (new TData_map( sdata, aLogger ) );
    std::unique_ptr<TProcessor_1>     myProc (new TProcessor_1( sproc, *myData, aLogger ));
    std::unique_ptr<TDataProcessor_3> myDataProc (new TDataProcessor_3( anId, move(myData), move(myProc), aLogger ));
    return myDataProc;
}

std::vector< IDataProcessor* > myPDPV;
std::vector< std::unique_ptr<IDataProcessor> > myDPV;

int main()
{
    // -------------------------------------------------------------------------------------
    // NOTE: Too verbose for clients. Should not need to know about TData_1 and TProcessor_1
    // -------------------------------------------------------------------------------------
    TData_1          data_1( "Dt1", myLogger ); // TODO: some json to init data
    TProcessor_1     processor_1( "Pr1", data_1, myLogger );
    TDataProcessor_1 myDataProcessor_1( "DP1", data_1, processor_1, myLogger );

    TData_1          data_2( "Dt2", myLogger );
    TProcessor_1     processor_2( "Pr2", data_2, myLogger );
    TDataProcessor_1 myDataProcessor_2( "DP2", data_2, processor_2, myLogger );

    // -------------------------------------------------------------------------------------
    // Specific implementation. New/delete of TData_1 and TProcessor_1 done internally
    // -------------------------------------------------------------------------------------
    TDPImplementation_1 myDataProcessor_3( "DP3", myLogger );

    // ----------------------------------------
    // Using pointers, delete at the end needed
    // ----------------------------------------
    TData_1             myData( "Dt4", myLogger );
    TProcessor_1        myProcessor( "Pr4", myData, myLogger );

    IDataProcessor* myDataProcessor_4 = new TDataProcessor_1( "DP4", myData, myProcessor, myLogger );
    IDataProcessor* myDataProcessor_5 = create_2( "DP5", myLogger );
    IDataProcessor* myDataProcessor_8 = new TDPImplementation_1( "DP8", myLogger );

    // DO NOT: myDPV.push_back( create_2( "DP" )); called destructor of pointer, not object -> Memory leak
    myPDPV.push_back(  myDataProcessor_4 ); // TDataProcessor_1
    myPDPV.push_back(  myDataProcessor_5 ); // TDataProcessor_2
    myPDPV.push_back( &myDataProcessor_2 ); // TDataProcessor_1
    myPDPV.push_back(  myDataProcessor_8 ); // TDPImplementation_1

    // ----------------------------------------
    // Using smart pointers, delete not needed
    // ----------------------------------------
    std::unique_ptr<IDataProcessor> myDataProcessor_6 = create_3( "DP6", myLogger );
    std::unique_ptr<IDataProcessor> myDataProcessor_9 (new TDPImplementation_1( "DP9", myLogger ));

    myDPV.push_back( move(myDataProcessor_6)      ); // TDataProcessor_3
    myDPV.push_back( move(myDataProcessor_9)      ); // TDPImplementation_1
    myDPV.push_back( create_3( "DP7", myLogger )  ); // OK, Destructor of object called at the end
    myDPV.push_back( create_4( "DP10", myLogger ) ); // TDataMap_1

    // ------------------------------------------------
    // Do some data processing
    // ------------------------------------------------
    simple_use(  myDataProcessor_1,   2.1 ,  4, true );
    simple_use( *myPDPV[2],          -7.67,  3, true ); // myDataProcessor_2
    simple_use(  myDataProcessor_3,  12.12, 12, true );
    simple_use( *myPDPV[0],           1.23,  5, true ); // myDataProcessor_4
    simple_use( *myPDPV[3],           0.23,  8, true ); // TDPImplementation_1
    simple_use( *myDataProcessor_5,   7.92,  3, true );
    simple_use( *myDPV[0],           -0.92,  3, true );
    simple_use( *myDPV[1],           -7.92,  3, true ); // TDPImplementation_1
    simple_use( *myDPV[2],            9.26, -2, true );
    simple_use( *myDPV[3],           10.10, -2, true );

    // ----------------------
    // Do not forget to clean
    // ----------------------
    delete myDataProcessor_4;
    delete myDataProcessor_5;
    delete myDataProcessor_8;

    // TESTS
    TTestSuite_myTests myTests1( "myTestSuite", myLogger );
//    myTests1.run_all();
    myTests1.execute();

    return 0;
}
