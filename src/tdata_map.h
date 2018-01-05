#ifndef TDATA_MAP_H
#define TDATA_MAP_H

#include "tintfdata.h"
#include "tintflogger.h"

//--------------------------------------
#include <map>
// TODO: Can we use double to store both double and int types instead?
//*
template <class T>
class TMAP
{
public:
    //TMAP(); // use to add elements to the map
    int add( std::string anId, T aValue );
    int set( std::string anId, T aValue );
    T   get( std::string anId           );
private:
    std::map<std::string, T> m_map;
};
/*/
class TMAP
{
public:
    //TMAP(); // use to add elements to the map
    int    add( std::string anId, double aValue );
    int    set( std::string anId, double aValue );
    double get( std::string anId );
private:
    std::map<std::string, double> m_map;
};
//*/

// --------------------------------------
class TData_map : public TIntfData
{
public:
    TData_map( std::string anId, TIntfLogger &aLogger );
    virtual ~TData_map();

    void defaultInit();

    // Interface TIntfData
    virtual void   set_1( const double aValue ); // Configure
    virtual double get_1()                     ;
    virtual void   set_2( const int    aValue );
    virtual int    get_2()                     ;
    virtual void   set_3( const double aValue ); // Runtime
    virtual double get_3()                     ;
    virtual void   set_4( const int    aValue );
    virtual int    get_4()                     ;
    virtual void   set_5( const double aValue ); // Results
    virtual double get_5()                     ;
    virtual void   set_6( const int    aValue );
    virtual int    get_6()                     ;


private:
    TData_map            ( const TData_map& ); // No copy constructor
    TData_map& operator= ( const TData_map& ); // No assign operator

    void   _add( std::string anItem, const double aValue );
    void   _set( std::string anItem, const double aValue );
    double _get( std::string anItem );

    // Use double to store both doubles and integers
    std::map<std::string, double> m_map;

    // TODO: Need to be public???
    TMAP< double >  m_map_double;
    TMAP< int    >  m_map_int;
//    TMAP  m_map_double;
//    TMAP  m_map_int;


    std::string   m_id;
    TIntfLogger & m_logger;
};

#endif // TDATA_MAP_H
