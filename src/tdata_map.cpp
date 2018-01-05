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

    _add( "d_1", 0.0 );
    _add( "i_2", 0.0 );
    _add( "d_3", 0.0 );
    _add( "i_4", 0.0 );
    _add( "d_5", 0.0 );
    _add( "i_6", 0.0 );
}

//--------------------
void TData_map::_add( std::string anItem, const double aValue )
{
    if(m_map.find( anItem ) == m_map.end()) { m_map.insert(std::make_pair( anItem, aValue )); }
    else                                    { m_logger.log( "Error adding " + anItem, m_id ); }
}

void TData_map::_set( std::string anItem, const double aValue )
{
    if(m_map.find( anItem ) != m_map.end()) { m_map[anItem] = aValue;                          }
    else                                    { m_logger.log( "Error setting " + anItem, m_id ); }
}

#include <assert.h>
double TData_map::_get( std::string anItem )
{
    if(m_map.find( anItem ) != m_map.end()) { return m_map[anItem];                            }
    else                                    { m_logger.log( "Error getting " + anItem, m_id ); }

    // TODO
    assert( 0 );
    return -1; // Not returned due to the assert
}

// -------------------
// Interface TIntfData
// -------------------
void   TData_map::set_1( const double aValue ) { _set( "d_1", aValue ); }
double TData_map::get_1()                      { return  _get( "d_1" ); }

void   TData_map::set_2( const int    aValue ) { _set( "i_2", aValue ); }
int    TData_map::get_2()                      { return  _get( "i_2" ); }

void   TData_map::set_3( const double aValue ) { _set( "d_3", aValue ); }
double TData_map::get_3()                      { return  _get( "d_3" ); }

void   TData_map::set_4( const int    aValue ) { _set( "i_4", aValue ); }
int    TData_map::get_4()                      { return  _get( "i_4" ); }

void   TData_map::set_5( const double aValue ) { _set( "d_5", aValue ); }
double TData_map::get_5()                      { return  _get( "d_5" ); }

void   TData_map::set_6( const int    aValue ) { _set( "i_6", aValue ); }
int    TData_map::get_6()                      { return  _get( "i_6" ); }

// ----------------------------------------------
// TMAP
// ----------------------------------------------
//*
template <class T>
int TMAP<T>::add( std::string anId, T aValue )
{
    if(m_map.find( anId ) == m_map.end()) // Not present
    {
//        std::cout << "Adding " << anId << std::endl;
        m_map.insert(std::make_pair( anId, aValue ));
        return 0;
    }
    return -1;
}

template <class T>
int TMAP<T>::set( std::string anId, T aValue )
{
    if(m_map.find( anId ) != m_map.end())
    {
//        std::cout << "Setting " << anId << std::endl;
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
    // TODO
    assert( 0 );
    return -1; // Not returned due to the assert
}
/*/

int TMAP::add( std::string anId, double aValue )
{
    if(m_map.find( anId ) != m_map.end())
    {
        m_map.insert(std::make_pair( anId, aValue ));
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
    // TODO
    assert( 0 );
    return -1; // Not returned due to the assert
}
//*/
