#ifndef TDPIMPLEMENTATION_1_H
#define TDPIMPLEMENTATION_1_H

#include "tintfdataprocessor.h"
#include "tintflogger.h"

#include "tdata_1.h"
#include "tprocessor_1.h"


class TDPImplementation_1 : public TIntfDataProcessor
{
public:
    TDPImplementation_1( std::string   anId
                       , TIntfLogger & aLogger );
    virtual ~TDPImplementation_1();

    // Interface TIntfDataProcessor
    virtual void        set_1( const double aValue );
    virtual void        set_4( const int    aValue );
    virtual double      get_5();
    virtual void        calculate_1();
    virtual void        enable_log( const bool enable );
    virtual std::string getId();

private:
    TDPImplementation_1            ( const TDPImplementation_1& ); // No copy constructor
    TDPImplementation_1& operator= ( const TDPImplementation_1& ); // No assign operator

    std::string    m_id;
    TData_1      * m_data;
    TProcessor_1 * m_processor;
    TIntfLogger  & m_logger;
};

#endif // TDPIMPLEMENTATION_1_H
