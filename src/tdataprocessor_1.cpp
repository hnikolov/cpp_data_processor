#include "tdataprocessor_1.h"


TDataProcessor_1::TDataProcessor_1(std::string anId, TIntfData &aData, TIntfProcessor &aProcessor, TIntfLogger &aLogger) :
    m_id       ( anId       ),
    m_data     ( aData      ),
    m_processor( aProcessor ),
    m_logger   ( aLogger    )
{
}

TDataProcessor_1::~TDataProcessor_1()
{
    m_logger.log( "Called destuctor", m_id );
}

// ----------------------------
// Interface TIntfDataProcessor
// ----------------------------
void TDataProcessor_1::set_1( const double aValue )
{
    m_data.set_1( aValue );
}

void TDataProcessor_1::set_4( const int aValue )
{
    m_data.set_4( aValue );
}

double TDataProcessor_1::get_5()
{
    return m_data.get_5();
}

void TDataProcessor_1::calculate_1()
{
    m_processor.calculate_1();
}

void TDataProcessor_1::enable_log( const bool enable )
{
    m_logger.enable( enable );
}
// ----------------------------
