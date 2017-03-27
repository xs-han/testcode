//============================================================================
// Name        : Tests.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "header/AllTests.h"

using namespace std;

int main()
{
    TestPtrs testptr;
    TestOpencvMat testMat;
    TestOpencvImage testopencvimage;
    TestOpencvKeypoints tockp;
	TestOpencvMyMatcher tmm;
	TestStdMap tsm;
	TestFunctionParameters tfp = TestFunctionParameters();
	TestArrayandPointer taap;
	TestBinFileIO tbfio;
	TestOpencvMatxCons tomc;
	TestOpencvDecUsingKey toduk;
	TestStdVectorExchange tstdvx;

	Tests::MyTest(tstdvx);

    return 0;
}
