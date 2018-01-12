#include "tdataprocessor_1.h"


TDataProcessor_1::TDataProcessor_1( std::string     anId
                                  , IData          &aData
                                  , IProcessor &aProcessor
                                  , ILogger    &aLogger) :
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

// ------------------------
// Interface IDataProcessor
// ------------------------
void        TDataProcessor_1::set_1( const double aValue )    { m_data.set_1( aValue );    }
void        TDataProcessor_1::set_4( const int aValue )       { m_data.set_4( aValue );    }
double      TDataProcessor_1::get_5()                         { return m_data.get_5();     }
void        TDataProcessor_1::calculate_1()                   { m_processor.calculate_1(); }
void        TDataProcessor_1::enable_log( const bool enable ) { m_logger.enable( enable ); }
std::string TDataProcessor_1::getId()                         { return m_id;               }

// =========================================================================================
TDataProcessor_2::TDataProcessor_2( std::string     anId
                                  , IData          *aData
                                  , IProcessor *aProcessor
                                  , ILogger    &aLogger) :
    m_id       ( anId    ),
    m_logger   ( aLogger )
{
    m_data      = aData;
    m_processor = aProcessor;
}

TDataProcessor_2::~TDataProcessor_2()
{
    delete m_processor;
    delete m_data;
    m_logger.log( "Called destuctor", m_id );
}

// ------------------------
// Interface IDataProcessor
// ------------------------
void        TDataProcessor_2::set_1( const double aValue )    { m_data->set_1( aValue );    }
void        TDataProcessor_2::set_4( const int aValue )       { m_data->set_4( aValue );    }
double      TDataProcessor_2::get_5()                         { return m_data->get_5();     }
void        TDataProcessor_2::calculate_1()                   { m_processor->calculate_1(); }
void        TDataProcessor_2::enable_log( const bool enable ) { m_logger.enable( enable );  }
std::string TDataProcessor_2::getId()                         { return m_id;                }

// =========================================================================================
TDataProcessor_3::TDataProcessor_3( std::string                     anId
                                  , std::unique_ptr<IData>          aData
                                  , std::unique_ptr<IProcessor> aProcessor
                                  , ILogger                    &aLogger) :
    m_id       ( anId       ),
    m_logger   ( aLogger    )
{
    m_data      = move( aData      );
    m_processor = move( aProcessor );
}

TDataProcessor_3::~TDataProcessor_3()
{
    m_logger.log( "Called destuctor", m_id );
}

// ------------------------
// Interface IDataProcessor
// ------------------------
void        TDataProcessor_3::set_1( const double aValue )    { m_data->set_1( aValue );    }
void        TDataProcessor_3::set_4( const int aValue )       { m_data->set_4( aValue );    }
double      TDataProcessor_3::get_5()                         { return m_data->get_5();     }
void        TDataProcessor_3::calculate_1()                   { m_processor->calculate_1(); }
void        TDataProcessor_3::enable_log( const bool enable ) { m_logger.enable( enable );  }
std::string TDataProcessor_3::getId()                         { return m_id;                }
// ------------------------
