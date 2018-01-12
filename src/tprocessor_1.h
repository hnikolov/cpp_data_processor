#ifndef TPROCESSOR_H
#define TPROCESSOR_H

#include "iprocessor.h"
#include "ilogger.h"
#include "idata.h"


class TProcessor_1 : public IProcessor
{
public:
    TProcessor_1( std::string anId, IData& aData, ILogger& aLogger );
    virtual ~TProcessor_1();

    // Interface TIntfProcessor
    virtual void calculate_1();
    virtual void calculate_2();
    virtual void calculate_3();

private:
    std::string   m_id;
    IData       & m_data;
    ILogger     & m_logger;
};

#endif // TPROCESSOR_H
