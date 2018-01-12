#include "tprocessor_1.h"

TProcessor_1::TProcessor_1( std::string anId, IData& aData, ILogger& aLogger ) :
    m_id    ( anId    ),
    m_data  ( aData   ),
    m_logger( aLogger )
{
}

TProcessor_1::~TProcessor_1()
{
    m_logger.log( "Called destuctor", m_id );
}

// --------------------
// Interface IProcessor
// --------------------
void TProcessor_1::calculate_1()
{
    m_data.set_5( m_data.get_1() + m_data.get_4() );
    m_logger.log( "Called calculate_1()", m_id);
}

void TProcessor_1::calculate_2()
{
    m_logger.log( "Called calculate_2()", m_id);
}

void TProcessor_1::calculate_3()
{
    m_logger.log( "Called calculate_3()", m_id);
}
// --------------------
