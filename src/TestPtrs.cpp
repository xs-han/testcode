#include "TestPtrs.h"

TestPtrs::TestPtrs()
{
    //ctor
}

TestPtrs::~TestPtrs()
{
    //dtor
}

void TestPtrs::RunTests() const
{
    cout << "This is a test of TestPtrs." << endl;
    int a = 1;
    int * p = & a;

    cout << "(p == &(*p)) is ";
    if (p == &(*p))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return;
}
