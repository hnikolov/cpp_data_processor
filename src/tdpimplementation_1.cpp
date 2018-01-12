#include "tdpimplementation_1.h"

TDPImplementation_1::TDPImplementation_1(std::string anId, ILogger &aLogger) :
    m_id       ( anId    ),
    m_logger   ( aLogger )
{
    std::string sdata = anId + "_data";
    std::string sproc = anId + "_proc";

    m_data      = new TData_1     ( sdata,          m_logger );
    m_processor = new TProcessor_1( sproc, *m_data, m_logger );
}

TDPImplementation_1::~TDPImplementation_1()
{
    delete m_data;
    delete m_processor;
    m_logger.log( "Called destuctor", m_id );
}

// ------------------------
// Interface IDataProcessor
// ------------------------
void        TDPImplementation_1::set_1( const double aValue )    { m_data->set_1( aValue );    }
void        TDPImplementation_1::set_4( const int aValue )       { m_data->set_4( aValue );    }
double      TDPImplementation_1::get_5()                         { return m_data->get_5();     }
void        TDPImplementation_1::calculate_1()                   { m_processor->calculate_1(); }
void        TDPImplementation_1::enable_log( const bool enable ) { m_logger.enable( enable );  }
std::string TDPImplementation_1::getId()                         { return m_id;                }
// ------------------------
