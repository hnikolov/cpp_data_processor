#include "tdata_map.h"

TData_map::TData_map( std::string anId, TIntfLogger &aLogger ) :
    m_id    ( anId    ),
    m_logger( aLogger )
{
    defaultInit();
}

TData_map::~TData_map()
{
    m_logger.log( "Called destuctor", m_id );
}

void TData_map::defaultInit()
{
    // Config
    m_map_double.add( "d_1", 0.0 );
    m_map_int.add(    "i_2",   0 );

    // Measured
    m_map_double.add( "d_3", 0.0 );
    m_map_int.add(    "i_4",   0 );

    // Results
    m_map_double.add( "d_5", 0.0 );
    m_map_int.add(    "i_6",   0 );

    m_map.insert(std::make_pair( "d_1", 0.0));
    m_map.insert(std::make_pair( "i_2", 0.0));
    m_map.insert(std::make_pair( "d_3", 0.0));
    m_map.insert(std::make_pair( "i_4", 0.0));
    m_map.insert(std::make_pair( "d_5", 0.0));
    m_map.insert(std::make_pair( "i_6", 0.0));
}

// -------------------
// Interface TIntfData
// -------------------
void   TData_map::set_1( const double aValue )
{
    if(m_map.find("d_1") != m_map.end()) { m_map["d_1"] = aValue;               }
    else                                 { m_logger.log( "Error set_1", m_id ); }
}

double TData_map::get_1()                      { return m_map["d_1"];  }

void   TData_map::set_2( const int    aValue )
{
    if(m_map.find("i_2") != m_map.end()) { m_map["i_2"] = aValue;               }
    else                                 { m_logger.log( "Error set_2", m_id ); }
}

int    TData_map::get_2()                      { return m_map["i_2"];     }

void   TData_map::set_3( const double aValue )
{
    if(m_map.find("d_3") != m_map.end()) { m_map["d_3"] = aValue;               }
    else                                 { m_logger.log( "Error set_3", m_id ); }
}

double TData_map::get_3()                      { return m_map["d_3"];  }

void   TData_map::set_4( const int    aValue )
{
    if(m_map.find("i_4") != m_map.end()) { m_map["i_4"] = aValue;               }
    else                                 { m_logger.log( "Error set_4", m_id ); }
}

int    TData_map::get_4()                      { return m_map["i_4"];     }

void   TData_map::set_5( const double aValue )
{
    if(m_map.find("d_5") != m_map.end()) { m_map["d_5"] = aValue;               }
    else                                 { m_logger.log( "Error set_5", m_id ); }
}

double TData_map::get_5()                      { return m_map["d_5"];  }

void   TData_map::set_6( const int    aValue )
{
    if(m_map.find("i_6") != m_map.end()) { m_map["i_6"] = aValue;               }
    else                                 { m_logger.log( "Error set_6", m_id ); }
}

int    TData_map::get_6()                      { return m_map["i_6"];     }

// ----------------------------------------------
// TMAP
// ----------------------------------------------
/*
template <class T>
int TMAP<T>::add( std::string anId, T aValue )
{
    if(m_map.find( anId ) != m_map.end())
    {
        m_map.insert(std::make_pair( anId, aValue));
        return 0;
    }
    return -1;
}

template <class T>
int TMAP<T>::set( std::string anId, T aValue )
{
    if(m_map.find( anId ) != m_map.end())
    {
        m_map[anId] = aValue;
        return 0;
    }
    return -1;
}

template <class T>
T TMAP<T>::get( std::string anId )
{
    if(m_map.find( anId ) != m_map.end())
    {
        return m_map[anId];
    }
    return NULL;
}
*/

int TMAP::add( std::string anId, double aValue )
{
    if(m_map.find( anId ) != m_map.end())
    {
        m_map.insert(std::make_pair( anId, aValue));
        return 0;
    }
    return -1;
}

int TMAP::set( std::string anId, double aValue )
{
    if(m_map.find( anId ) != m_map.end())
    {
        m_map[anId] = aValue;
        return 0;
    }
    return -1;
}

double TMAP::get( std::string anId )
{
    if(m_map.find( anId ) != m_map.end())
    {
        return m_map[anId];
    }
    return NULL;
}
