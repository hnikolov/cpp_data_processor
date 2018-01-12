#ifndef TDATAPROCESSOR_1_H
#define TDATAPROCESSOR_1_H

#include "idata.h"
#include "tintfprocessor.h"
#include "tintflogger.h"
#include "tintfdataprocessor.h"

// -----------------------------------------------
// Implements the interface exposed to clients
// Contains only references to other interfaces
// -----------------------------------------------
class TDataProcessor_1 : public TIntfDataProcessor
{
public:
    TDataProcessor_1( std::string      anId
                    , IData      & aData
                    , TIntfProcessor & aProcessor
                    , TIntfLogger    & aLogger );
    virtual ~TDataProcessor_1();

    // Interface TIntfDataProcessor
    virtual void        set_1( const double aValue );
    virtual void        set_4( const int    aValue );
    virtual double      get_5();
    virtual void        calculate_1();
    virtual void        enable_log( const bool enable );
    virtual std::string getId();

private:
    std::string      m_id;
    IData      & m_data;
    TIntfProcessor & m_processor;
    TIntfLogger    & m_logger;
};


// ----------------------------------------------------------------
// Implements the interface exposed to clients
// Contains pointers to other interfaces: deleted in the destructor
// ----------------------------------------------------------------
#include <memory>

class TDataProcessor_2 : public TIntfDataProcessor
{
public:
    TDataProcessor_2( std::string      anId
                    , IData          * aData
                    , TIntfProcessor * aProcessor
                    , TIntfLogger    & aLogger );
    virtual ~TDataProcessor_2();

    // Interface TIntfDataProcessor
    virtual void        set_1( const double aValue );
    virtual void        set_4( const int    aValue );
    virtual double      get_5();
    virtual void        calculate_1();
    virtual void        enable_log( const bool enable );
    virtual std::string getId();

private:
    std::string      m_id;
    IData          * m_data;
    TIntfProcessor * m_processor;
    TIntfLogger    & m_logger;
};

// -----------------------------------------------
// Implements the interface exposed to clients
// Contains smart pointers to other interfaces
// -----------------------------------------------
class TDataProcessor_3 : public TIntfDataProcessor
{
public:
    TDataProcessor_3( std::string                     anId
                    , std::unique_ptr<IData>          aData
                    , std::unique_ptr<TIntfProcessor> aProcessor
                    , TIntfLogger                   & aLogger );
    virtual ~TDataProcessor_3();

    // Interface TIntfDataProcessor
    virtual void        set_1( const double aValue );
    virtual void        set_4( const int    aValue );
    virtual double      get_5();
    virtual void        calculate_1();
    virtual void        enable_log( const bool enable );
    virtual std::string getId();

private:
    std::string                       m_id;
    std::unique_ptr< IData          > m_data;
    std::unique_ptr< TIntfProcessor > m_processor;
    TIntfLogger                     & m_logger;
};

#endif // TDATAPROCESSOR_1_H
