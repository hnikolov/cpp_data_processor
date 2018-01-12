#include "ttestsuite.h"


TTestSuite::TTestSuite(std::string anId, ILogger &aLogger):
    m_run   (       0 ),
    m_fail  (       0 ),
    m_id    (    anId ),
    m_logger( aLogger )
{
}

std::string TTestSuite::getResultMessage()
{
    std::ostringstream result_msg;
    result_msg << "Total Run: " << m_run ;

    if( m_fail > 0 ) { result_msg << " .. (" << m_fail << "-)"; }
    else             { result_msg << " .. OK";                  }

    return result_msg.str();
}

void TTestSuite::run_all()
{
    m_logger.log( "Executing tests...", m_id );
    // TODO: Filter tests to be run

    for( auto&& t : m_tests )
    {
        t->execute();
        m_logger.log( t->getResultMessage(), t->getId() );
        m_run  += t->getRun();
        m_fail += t->getFail();
    }
    // if (VERBOSE)
    m_logger.log( getResultMessage(), m_id );
}
