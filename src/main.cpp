#include "tdata_1.h"
#include "tprocessor_1.h"
#include "tlogger_1.h"
#include "tdataprocessor_1.h"
#include "tdpimplementation_1.h"

#include <iostream>
#include <vector>


TLogger_1 myLogger;

void simple_use( TIntfDataProcessor & myDataProcessor, double aDouble, int anInt, bool aLogEn = true )
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
    std::cout << std::endl;
}


TDataProcessor_2* create_2( )
{
    TData_1* myData = new TData_1( "Dt5", myLogger );
    return new TDataProcessor_2( "DP5", myData, new TProcessor_1( "Pr5", *myData, myLogger ), myLogger );
}

std::unique_ptr<TIntfDataProcessor> create_3( )
{
    std::unique_ptr<TData_1>        myData (new TData_1( "Dt6", myLogger ) );
    std::unique_ptr<TProcessor_1>   myProc (new TProcessor_1( "Pr6", *myData, myLogger ));
    std::unique_ptr<TDataProcessor_3> myDataProc (new TDataProcessor_3( "DP6", move(myData), move(myProc), myLogger ));
    return myDataProc;
}


// ------------------------------------------------------------------------------
TData_1          myData( "Dt4", myLogger );
TProcessor_1     myProcessor( "Pr4", myData, myLogger );

TIntfDataProcessor* create_1( )
{
    return new TDataProcessor_1( "DP4", myData, myProcessor, myLogger );
}
// ------------------------------------------------------------------------------

//std::vector< TIntfDataProcessor* > myDPV;
std::vector< std::unique_ptr<TIntfDataProcessor> > myDPV;

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

    // --------------------------------------------------------------------------------------------------------
    // NOTE: Too specific for clients. What if we want to use alternative TData and TProcessor implementations?
    // --------------------------------------------------------------------------------------------------------
    TDPImplementation_1 myDataProcessor_3( "DP3", myLogger );
    // --------------------------------------------------------------------------------------------------------

    TIntfDataProcessor* myDataProcessor_4 = create_1();
    TIntfDataProcessor* myDataProcessor_5 = create_2();
//    std::unique_ptr<TIntfDataProcessor> myDataProcessor_4 (create_1());
//    std::unique_ptr<TIntfDataProcessor> myDataProcessor_5 (create_2());

    std::unique_ptr<TIntfDataProcessor> myDataProcessor_6 (create_3());
    myDPV.push_back( move(myDataProcessor_6) );

    myDPV.push_back( create_3() );

//    myDPV.push_back( myDataProcessor_4 );
//    myDPV.push_back( myDataProcessor_5 );

    simple_use(  myDataProcessor_1,   2.1 ,  4, true );
    simple_use(  myDataProcessor_2,  -7.67,  3, true );
    simple_use(  myDataProcessor_3,  12.12, 12, true );
    simple_use( *myDataProcessor_4,   1.23,  5, true );
    simple_use( *myDataProcessor_5,   7.92,  3, true );
//    simple_use( *myDPV[0],   1.23,  5, true );
//    simple_use( *myDPV[1],   7.92,  3, true );
    simple_use( *myDPV[0],   -0.92,  3, true );
    simple_use( *myDPV[1],   -7.92,  3, true );

    delete myDataProcessor_4;
    delete myDataProcessor_5;

    // --------------------------------------------------------------------------------------------------------
    // QUESTION: What if we want to use alternative implementations, e.g., TData_2 and TProcessor_2, which
    //           implement the same interfaces?
    // --------------------------------------------------------------------------------------------------------
    //
    // 1) Use the same TDataProcessor_1 class. But want to avoid the knowledge about TData and TProcessor
    // --------------------------------------------------------------------------------------------------------
    // TData_2          alt_data_2( "Dt2", myLogger );
    // TProcessor_2     alt_processor_2( "Pr2", alt_data_2, myLogger );
    // TDataProcessor_1 myDataProcessor_2( "DP2", alt_data_2, alt_processor_2, myLogger );
    //
    // 2) Need to create another class, e.g, TDPImplementation_2
    // --------------------------------------------------------------------------------------------------------
    // TDPImplementation_2 myDataProcessor_3( "DP3", myLogger );
    //
    // 3) Object factory in combination with TDataProcessor_1?

    return 0;
}
