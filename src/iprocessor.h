#ifndef TINTFPROCESSOR_H
#define TINTFPROCESSOR_H

struct IProcessor
{
    virtual ~IProcessor() {}

    virtual void calculate_1() = 0;
    virtual void calculate_2() = 0;
    virtual void calculate_3() = 0;
};

#endif // TINTFPROCESSOR_H
