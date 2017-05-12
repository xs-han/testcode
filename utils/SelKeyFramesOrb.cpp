#include <iostream>
#include "AllTests.h"

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        cerr << "Usage: selKeyFrames InputDir OutputDir with Orb";
        exit(-1);
    }
    string inputDir = argv[1], outputDir = argv[2];
    TestOpencvSelKeyFrames tosk;

    tosk.GetAllFiles(inputDir, outputDir);
    tosk.CalcKeyFramesOrb(8,2000,0.5);
}
