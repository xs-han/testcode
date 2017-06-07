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
    TestOpencvMyMatcher tmm; tmm.setMatchFiles("/home/xushen/Desktop/MediaSoc/KeyFrames/forward/000176.jpg",
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
    TestOpencvMyMatcher tmmfiles;
    tmmfiles.getKeyAndDescs("/home/xushen/Desktop/MediaSoc/KeyFrames/forward/000204+85.yaml",tmmfiles.img1, tmmfiles.key1, tmmfiles.desc1);
    tmmfiles.getKeyAndDescs("/home/xushen/Desktop/MediaSoc/KeyFrames/rleft/000196.yaml", tmmfiles.img2, tmmfiles.key2, tmmfiles.desc2);

    Tests::MyTest2(tmmfiles);

    return 0;
}
