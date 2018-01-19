#include "ttestsuite.h"


TTestSuite::TTestSuite(std::string anId, ILogger &aLogger):
    BTest   (    anId ),
    m_logger( aLogger )
{
}

void TTestSuite::add( BTest* aTest )
{
    m_tests.push_back( UPtrBaseTest( aTest ));
}

void TTestSuite::execute()
{
    m_logger.log( "------------------", getId() );
    // m_logger.enable( false );
    // TODO: Filter tests to be run

    for( auto&& t : m_tests )
    {
        t->execute();
        m_logger.log( t->getResultMessage(), t->getId() );
        incRun ( t->getRun()  );
        incFail( t->getFail() );
    }
    // if (VERBOSE)
    m_logger.enable( true );
    m_logger.log( "------------------", getId() );
}

void TTestSuite::logResults()
{
    m_logger.log( getResultMessage(), getId() );
}
