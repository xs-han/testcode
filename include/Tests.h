#ifndef TESTS_H
#define TESTS_H

#include <iostream>

using namespace std;

class Tests
{
    public:
        Tests();
        virtual void RunTests() const =0;
        virtual void RunTests() {}
        virtual ~Tests();
        static void MyTest(const Tests & t){t.RunTests();}
        static void MyTest2(Tests & t){t.RunTests();}

    protected:

    private:
};

#endif // TESTS_H
