#ifndef TPROCESSOR_H
#define TPROCESSOR_H

#include "tintfprocessor.h"
#include "tintflogger.h"
#include "tintfdata.h"


class TProcessor_1 : public TIntfProcessor
{
public:
    TProcessor_1( std::string anId, TIntfData& aData, TIntfLogger& aLogger );
    virtual ~TProcessor_1();

    // Interface TIntfProcessor
    virtual void calculate_1();
    virtual void calculate_2();
    virtual void calculate_3();

private:
    std::string   m_id;
    TIntfData   & m_data;
    TIntfLogger & m_logger;
};

#endif // TPROCESSOR_H
