//============================================================================
// Name        : Tests.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "AllTests.h"

using namespace std;

int main()
{
    TestPtrs testptr;
    TestOpencvMat testMat;
    TestOpencvImage testopencvimage;
    TestOpencvKeypoints tockp;
    TestOpencvMyMatcher tmm; tmm.setMatchFiles("/home/xushen/Desktop/MediaSoc/KeyFrames/forward/000159.jpg",
                                               "/home/xushen/Desktop/MediaSoc/KeyFrames/rleft/000191.jpg");
	TestStdMap tsm;
	TestFunctionParameters tfp = TestFunctionParameters();
	TestArrayandPointer taap;
	TestBinFileIO tbfio;
	TestOpencvMatxCons tomc;
	TestOpencvDecUsingKey toduk;
	TestStdVectorExchange tstdvx;
	TestOpencvVideoCapture tovc;
    TestStdCopy tsc;
    TestOpencvSurf tos;

    Tests::MyTest(tmm);

    return 0;
}
