#ifndef TESTOPENCVSURF_H
#define TESTOPENCVSURF_H

#include "TestOpencv.h"

class TestOpencvSurf: public TestOpencv
{
public:
    TestOpencvSurf();
    virtual ~TestOpencvSurf();
    void RunTests() const;
};

#endif // TESTOPENCVSURF_H
