#ifndef TEST_EXAMPLE_H
#define TEST_EXAMPLE_H

#include "btest.h"

#include <iostream>
#include <sstream>


class TestExample : public BTest
{
public:
    explicit TestExample( std::string anId );

    virtual void execute();

private:
    std::string run_test_1(); // Example test, succeeds
    std::string run_test_2(); // Example test, fails on purpose
};

#endif // TEST_EXAMPLE_H
